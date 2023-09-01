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
};

typedef struct _sttResult SpeeduinoResult;
struct _sttResult
{
    long sValue;
    byte sValueByte1;
    byte sValueByte2;
    boolean errorFree;
};

#endif
