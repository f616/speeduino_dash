#include "arduino.h"
#include "defines.h"
#include "speedvars.h"
#include "speeduinodata.h"
#include "dwindata.h"

SpeeduinoData SData(&Serial1);
DwinData dwinData(&Serial2);

long lastReads[NUMBER_OF_SPEEDUINO_AVAILABLE_DEVICES];

void setup()
{
    Serial.begin(115200, SERIAL_8N1, RXD0, TXD0);  // Integrated Serial
    Serial1.begin(115200, SERIAL_8N1, RXD1, TXD1); // Speeduino
    Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2); // DWIN Display
    if (DEBUG_MODE >= 1)
    {
        Serial.println("Serial Txd is on pin: " + String(TXD0));
        Serial.println("Serial Rxd is on pin: " + String(RXD0));
        Serial.println("Serial1 Txd is on pin: " + String(TXD1));
        Serial.println("Serial1 Rxd is on pin: " + String(RXD1));
        Serial.println("Serial2 Txd is on pin: " + String(TXD2));
        Serial.println("Serial2 Rxd is on pin: " + String(RXD2));
    }
}

void loop()
{
    char buffer[200];
    char sValueName[80];

    for (int i = 0; i < NUMBER_OF_SPEEDUINO_AVAILABLE_DEVICES; i++)
    {
        if (speeduinodDevice[i].selected)
        {
            if ((millis() - lastReads[i]) > speeduinodDevice[i].freqRate)
            {
                memset(sValueName, 0, sizeof sValueName); // filling the array with meaningless values
                memset(buffer, 0, sizeof buffer);         // filling the array with meaningless values

                SpeeduinoResult resultGetFromSpeed = SData.getDataFromLocation(speeduinodDevice[i].lowByte, speeduinodDevice[i].numBytes);
                if (resultGetFromSpeed.errorFree)
                {
                    bool resultDwin = dwinData.sendDataToDwin(speeduinodDevice[i].dwinVPaddr1, speeduinodDevice[i].dwinVPaddr2, resultGetFromSpeed.sValueByte1, resultGetFromSpeed.sValueByte2);
                    if (resultDwin)
                    {
                        lastReads[i] = millis();
                    }
                    if (DEBUG_MODE >= 1)
                    {
                        long value = resultGetFromSpeed.sValue;
                        strcpy_P(sValueName, speeduinodDevice[i].name);
                        Serial.print("+>\t");
                        Serial.print(value);
                        Serial.print("\t+<\t");
                        Serial.print(i);
                        Serial.print("\t|\t");
                        Serial.print(speeduinodDevice[i].lowByte);
                        Serial.print("\t");
                        Serial.print(speeduinodDevice[i].numBytes);
                        Serial.print("\t|\t");
                        Serial.println(sValueName);
                    }
                }
            }
        }
    }
}
