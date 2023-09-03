#ifndef __STRUCTURES_H__
#define __STRUCTURES_H__

#include <Arduino.h>

/* Structures */
typedef struct _speeduinoDataList speeduinoDataList;
struct _speeduinoDataList
{
    const boolean selected;
    const uint16_t freqRate;
    const uint16_t lowByte;
    const uint16_t numBytes;
    const char *name PROGMEM;
    const uint16_t dwinValueVPaddr;
    const uint16_t dwinFreqVPaddr;
    const uint16_t dwinToggleVPaddr;
};

typedef struct _sttResult SpeeduinoResult;
struct _sttResult
{
    long sValue;
    byte sValueByte1;
    byte sValueByte2;
    boolean errorFree;
};

typedef struct _sttDwinRead DwinReading;
struct _sttDwinRead
{
    int16_t Value;
    int16_t vpAddr;
    boolean errorFree;
};

#endif
