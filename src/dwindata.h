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

    boolean resetToDefault(speeduinoDataList *data, uint16_t *DeviceFreq, boolean *DeviceToggle);
    // Sends the factory reset values to DWIN

    boolean sendDataToDwin(uint16_t vpAddr, char value1, char value2);
    // Receive the information to send to the DWIN display and buld the frame to
    // send through the private writeDwin method.

    DwinReading readDataFromDwin();
    // reads the data from the DWIN and passes it to be processed in the next function

private:
    // private methods
    Stream *_port;
    // Serial port to use on requesting device

    boolean writeDwin(byte frame[]);
    // It sends the data to the DWIN display.
};

#endif

/*

5A A5 06 83 01 08 01 00 01
5A A5 06 83 01 08 01 00 00

5A A5 06 83 01 04 01 00 64
5A A5 06 83 01 04 01 00 C8
5A A5 06 83 01 04 01 01 2C
5A A5 06 83 01 04 01 01 90

*/