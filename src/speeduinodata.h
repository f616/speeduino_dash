#ifndef __SPEEDUINODATA_H__
#define __SPEEDUINODATA_H__

#include "Arduino.h"
#include "structures.h"

class SpeeduinoData
{
public:
    // public methods to be used in the mail loop
    SpeeduinoData(Stream *port); // constructor
    // Defines the port used to request & receive data from Speeduino Arduino, use e &Serial1 for Serial 1.

    SpeeduinoResult getDataFromLocation(byte location, byte length);
    // get data from an user-defined byte location and length.

private:
    // private methods
    Stream *_port;
    // Serial port to use on requesting device

    SpeeduinoResult getSpeeduinoData(byte getData[2]);
    // It gets the data from the speeduino.

    SpeeduinoResult transformsData(byte dataStart, int value);
    // It transforms the data to a more meaningful value
};

#endif