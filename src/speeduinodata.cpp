#include "Arduino.h"
#include "defines.h"
#include "structures.h"
#include "speeduinodata.h"

SpeeduinoData::SpeeduinoData(Stream *port)
{
    _port = port;
}

SpeeduinoResult SpeeduinoData::getSpeeduinoData(byte getData[2])
{
    // Gets the data from the speeduiono
    byte dataStart = getData[0];
    byte noBytes = getData[1];
    int speedValue = 0; // return value
    char buffer[20];
    SpeeduinoResult result;

    boolean received = false;
    const byte requestData = 0x72; // the letter "r" in hex ,could send the integer or char but being consistent :-)
    const byte canID = 0xC7;       // speeduino canbus ID; i don't know what this is so I picked one at random.
    // we are not using canbus but Speeduino expects it
    const byte rCommand = 0x30;                       // "r" type command
    uint8_t speedyResponse[20];                       // The data buffer for the Serial data. This is longer than needed, just in case
    memset(speedyResponse, 0, sizeof speedyResponse); // filling the array with meaningless values

    // make two byte hex values to send to speeduino
    byte startLSB = lowByte(dataStart); // high and low bytes for start and length of data sequence
    byte startMSB = highByte(dataStart);
    byte lengthLSB = lowByte(noBytes); // high ansd low bytes for length of data
    byte lengthMSB = highByte(noBytes);

    // make an array of the bytes to send to start transmission of the data
    byte sendSequence[] = {requestData, canID, rCommand, startLSB, startMSB, lengthLSB, lengthMSB};
    _port->write(sendSequence, 7); // send the sequence to the ESP32

    delay(5); // try waiting for response

    uint8_t bytesRead = _port->readBytes(speedyResponse, 2 + noBytes);
    byte firstByte = speedyResponse[0];

    if (DEBUG_MODE >= 2)
    {
        sprintf(buffer, "##>\t\tbytesRead\t%d", bytesRead);
        Serial.println(buffer);
        for (byte i = 0; i < (bytesRead + 1); i++)
        {
            sprintf(buffer, "b%d>\t\t%d\t\t0x%02X\t\t%c", i, speedyResponse[i], speedyResponse[i], speedyResponse[i]);
            Serial.println(buffer);
        }
        sprintf(buffer, "##>\t\tfirstByte\t0x%02X (%d)", firstByte, firstByte);
        Serial.println(buffer);
    }

    if (firstByte == 0x72) // 0x72 (114) is confirmation, we  have data back, so process it
    {
        // byte dataTypeConfirmationByte = _port->read(); // next byte in buffer should be the data type confirmation. ignore for now
        byte dataTypeConfirmationByte = speedyResponse[1]; // next byte in buffer should be the data type confirmation. ignore for now
        if (DEBUG_MODE >= 2)
        {
            sprintf(buffer, "##>\t\tConfirmByte\t0x%02X (%d)", dataTypeConfirmationByte, dataTypeConfirmationByte);
            Serial.println(buffer);
        }
        if (dataTypeConfirmationByte == 0x30) // 0x30 (48) is confirmation, we  have data back, so process it
        {                                     // The port will now transmit a single byte in hex ,this is the type of the "r" type command about to be sent,This confirms what was requested (this is typically 0x30).
            byte firstByte;
            byte secondByte;
            if (noBytes == 1) // if there is supposed to only be one byte then do another read and save the value
            {
                firstByte = speedyResponse[2];
                secondByte = 0;
                speedValue = (secondByte << 8) | firstByte; // join high and low bytes into integer value
                if (DEBUG_MODE >= 2)
                {
                    sprintf(buffer, "##>\t\tpayload(1b)\t0x%02X (%d)", firstByte, firstByte);
                    Serial.println(buffer);
                }
            }
            else if (noBytes == 2)
            {
                // there are two bytes of data so have to do two reads and join the bytes into an integer
                firstByte = speedyResponse[2];
                secondByte = speedyResponse[3];
                speedValue = (secondByte << 8) | firstByte; // join high and low bytes into integer value
                if (DEBUG_MODE >= 2)
                {
                    sprintf(buffer, "##>\t\tpayload(2b)\t0x%04X 0x%04X (%d %d)", (secondByte << 8), firstByte, (secondByte << 8), firstByte);
                    Serial.println(buffer);
                }
            }
            // Transforms the value to a more meaningful value
            SpeeduinoResult transformedData = transformsData(dataStart, speedValue);
            received = true;
            result.sValue = transformedData.sValue;
            result.sValueByte1 = transformedData.sValueByte1;
            result.sValueByte2 = transformedData.sValueByte2;
            result.errorFree = transformedData.errorFree;
        }
    }
    if (received != true)
    {
        if (DEBUG_MODE >= 2)
        {
            sprintf(buffer, "##>\t\t-->> ERROR <<--");
            Serial.println(buffer);
        }
        delay(50);
        result.sValue = 0;
        result.errorFree = false;
    }
    if (DEBUG_MODE >= 2)
    {
        sprintf(buffer, "##>\t\terrorFree\t%d", result.errorFree);
        Serial.println(buffer);
        sprintf(buffer, "##>\t\tsValue\t\t%d", result.sValue);
        Serial.println(buffer);
        Serial.println("--\t\t------- END -------");
    }
    return result;
}

SpeeduinoResult SpeeduinoData::getDataFromLocation(byte location, byte length)
{
    // gets data from speeduino one measere at a time using the location and the number of bytes.
    // location and length from https://wiki.speeduino.com/en/Secondary_Serial_IO_interface
    SpeeduinoResult result;
    byte dataToGet[2] = {location, length};

    result.errorFree = false;
    result.sValue = 0;
    result = getSpeeduinoData(dataToGet);
    return result;
}

SpeeduinoResult SpeeduinoData::transformsData(byte dataStart, int value)
{
    SpeeduinoResult result;

    result.errorFree = false;
    result.sValue = 0;
    switch (dataStart)
    {
    case 6:   // IAT: must be subtracted by the CALIBRATION_TEMPERATURE_OFFSET (40C)
    case 7:   // coolant temp: must be subtracted by the CALIBRATION_TEMPERATURE_OFFSET (40C)
    case 111: // fuelTemp: must be subtracted by the CALIBRATION_TEMPERATURE_OFFSET (40C)
        value = value - 40;
        break;
    default:
        value = value;
        break;
    }

    result.sValue = value;
    result.sValueByte1 = highByte(value);
    result.sValueByte2 = lowByte(value);
    result.errorFree = true;
    return result;
}