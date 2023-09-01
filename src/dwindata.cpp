#include "Arduino.h"
#include "defines.h"
#include "structures.h"
#include "dwindata.h"

DwinData::DwinData(Stream *port)
{
    _port = port;
}

boolean DwinData::sendDataToDwin(uint16_t vpAddr, char value1, char value2)
{
    byte vpAddrLow = lowByte(vpAddr); // high and low bytes for DWIN VPAddr
    byte vpAddrHigh = highByte(vpAddr);
    byte frame[] = {0x5A, 0xA5, 0x05, 0x82, vpAddrHigh, vpAddrLow, value1, value2};
    if (DEBUG_MODE >= 2)
    {
        Serial.print("-->\tsendDataToDwin vpAddr\t\t");
        Serial.print("0x");
        Serial.print(highByte(vpAddr), HEX);
        Serial.print("\t0x");
        Serial.print(lowByte(vpAddr), HEX);
        Serial.print("\t0x");
        Serial.print(vpAddr, HEX);
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