#include "Arduino.h"
#include "defines.h"
#include "structures.h"
#include "dwindata.h"

DwinData::DwinData(Stream *port)
{
    _port = port;
}

boolean DwinData::resetToDefault(speeduinoDataList *data)
{
    for (int i = 0; i < NUMBER_OF_SPEEDUINO_AVAILABLE_DEVICES; i++)
    {
        uint16_t vpAddr = data[i].dwinFreqVPaddr;
        char value1 = highByte(data[i].freqRate);
        char value2 = lowByte(data[i].freqRate);
        if (DEBUG_MODE >= 2)
        {
            char tmp[24];
            Serial.print("-->\tresetToDefault\tFreq\t");
            Serial.print(i);
            sprintf(tmp, "\t0x%.4X\t0x%.2X\t0x%.2X", vpAddr, value1, value2);
            Serial.print(tmp);
            Serial.print("\t");
            Serial.print(data[i].name);
            Serial.println("");
        }
        sendDataToDwin(vpAddr, value1, value2);
        vpAddr = data[i].dwinToggleVPaddr;
        value1 = highByte(data[i].selected);
        value2 = lowByte(data[i].selected);
        if (DEBUG_MODE >= 2)
        {
            char tmp[24];
            Serial.print("-->\tresetToDefault\tToggle\t");
            Serial.print(i);
            sprintf(tmp, "\t0x%.4X\t0x%.2X\t0x%.2X", vpAddr, value1, value2);
            Serial.print(tmp);
            Serial.print("\t");
            Serial.print(data[i].name);
            Serial.println("");
        }
        sendDataToDwin(vpAddr, value1, value2);
    }
    return true;
}

boolean DwinData::sendDataToDwin(uint16_t vpAddr, char value1, char value2)
{
    byte vpAddrLow = lowByte(vpAddr); // high and low bytes for DWIN VPAddr
    byte vpAddrHigh = highByte(vpAddr);
    byte frame[] = {0x5A, 0xA5, 0x05, 0x82, vpAddrHigh, vpAddrLow, value1, value2};
    /*
    0x5A Header
    0xA5 Header
    0x05 Number of bytes to be sent
    0x82 Write command (0x83 read command)
    vpAddrHigh Write address byte1
    vpAddrLow Write address byte2
    value1 Write value high byte
    value2 Write value low byte
    */
    if (DEBUG_MODE >= 2)
    {
        char tmp[24];
        Serial.print("-->\tsendDataToDwin vpAddr\t");
        sprintf(tmp, "0x%.2X\t0x%.2X\t0x%.2X", highByte(vpAddr), lowByte(vpAddr), vpAddr);
        Serial.print(tmp);
        Serial.print("\tPayload\t");
        for (int i = 0; i < sizeof frame; i++)
        {
            sprintf(tmp, "0x%.2X ", frame[i]);
            Serial.print(tmp);
        }
        Serial.println("");
    }
    boolean resultWr = writeDwin(frame);
    return resultWr;
}

boolean DwinData::writeDwin(byte frame[])
{
    _port->write(frame, 8); // send the sequence to the DWIN display
    if (DEBUG_MODE >= 2)
    {
        Serial.print("-->\tWriting to DWIN\t");
        for (int ii = 0; ii < 8; ii++)
        {
            Serial.print(" 0x");
            Serial.print(frame[ii], HEX);
        }
        Serial.println("");
    }
    return true;
}

DwinReading DwinData::readDataFromDwin()
{
    // Serial.println("Begin Data Reading... ");
    DwinReading result;
    result.errorFree = false;
    byte dwinPayload[10];
    memset(dwinPayload, 0, sizeof dwinPayload); // filling the array with meaningless values

    byte firstByte = _port->read();
    if (firstByte == 0x5A)
    {
        byte secondByte = _port->read();
        if (secondByte == 0xA5)
        {
            byte thirdByte = _port->read();
            byte forthByte = _port->read();
            if (forthByte == 0x83) // 5A 05 nn 83 -> read the remaining sequence
            {
                int lengthDwinPayload = sizeof dwinPayload;
                int adjDataLength = min(thirdByte * 1, lengthDwinPayload) - 1; // -1 because the forthByte has already been stored
                for (int i = 0; i < adjDataLength; i++)
                {
                    dwinPayload[i] = _port->read();
                }
                if (DEBUG_MODE >= 1)
                {
                    Serial.print("-->\tRead from DWIN\tlength: ");
                    Serial.print(adjDataLength + 1);
                    Serial.print("\t");
                    char tmp[10];
                    sprintf(tmp, "0x%.2X 0x%.2X 0x%.2X 0x%.2X ", firstByte, secondByte, thirdByte, forthByte);
                    Serial.print(tmp);
                    for (int j = 0; j < adjDataLength; j++)
                    {
                        char tmp[24];
                        sprintf(tmp, "0x%.2X ", dwinPayload[j]);
                        Serial.print(tmp);
                    }
                    Serial.println("");
                }
                result.errorFree = true;
            }
        }
    }
    return result;
}