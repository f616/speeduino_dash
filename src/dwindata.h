#ifndef __DWINDATA_H__
#define __DWINDATA_H__

#include "Arduino.h"
#include "structures.h"

class DwinData
{
public:
    // public methods to be used in the mail loop
    DwinData(Stream *port); // constructor
    // Defines the port used to rsend data to the DWIN display, use e &Serial2 for Serial 2.

    boolean sendDataToDwin(uint16_t vpAddr, char value1, char value2);
    // Receive the information to send to the DWIN display and buld the frame to
    // send through the private writeDwin method.

private:
    // private methods
    Stream *_port;
    // Serial port to use on requesting device

    boolean writeDwin(byte frame[]);
    // It sends the data to the DWIN display.
};

#endif