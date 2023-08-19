#include "Arduino.h"
#include "defines.h"
#include "structures.h"
#include "dwindata.h"

DwinData::DwinData(Stream *port)
{
    _port = port;
}

boolean DwinData::sendDataToDwin(char vpAddr1, char vpAddr2, char value1, char value2)
{
    byte frame[] = {0x5A, 0xA5, 0x05, 0x82, vpAddr1, vpAddr2, value1, value2};
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