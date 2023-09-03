#include "arduino.h"
#include "defines.h"
#include "speedvars.h"
#include "speeduinodata.h"
#include "dwindata.h"

SpeeduinoData SData(&Serial1);
DwinData dwinData(&Serial2);

long lastReads[NUMBER_OF_SPEEDUINO_AVAILABLE_DEVICES];

TaskHandle_t TaskReadDwin;

void updSpeeduinoVar(int16_t value, int16_t addr)
{
    for (int i = 0; i < NUMBER_OF_SPEEDUINO_AVAILABLE_DEVICES; i++)
    {
        if (speeduinodDevice[i].dwinFreqVPaddr == addr)
        {
            // Serial.println("** faz update à variável ** freq");
            speeduinodDevice[i].freqRate = value;
            break;
        }
        if (speeduinodDevice[i].dwinToggleVPaddr == addr)
        {
            // Serial.println("** faz update à variável ** toggle");
            boolean bValue = false;
            if (value > 0)
            {
                bValue = true;
            }
            else
            {
                bValue = false;
                dwinData.sendDataToDwin(speeduinodDevice[i].dwinValueVPaddr, 0, 0); // sets the value to zero in DWIN
            }
            speeduinodDevice[i].selected = bValue;
            break;
        }
    }
    if (DEBUG_MODE >= 1)
    {
        char tmp[40];
        sprintf(tmp, "Addr:\t0x%.4X\tValue:\t%i", addr, value);
        Serial.println(tmp);
    }
}

void processDwinData(int16_t value, int16_t addr)
{
    if (addr == 9000 && value == 1)
    {
        // reboot ESP32
        ESP.restart();
    }
    else if (addr == 9010 && value == 1)
    {
        // factory reset the values
        dwinData.resetToDefault(speeduinodDevice);
    }
    else
    {
        updSpeeduinoVar(value, addr);
    }
}

void TaskReadDwinCode(void *pvParameters)
{
    Serial.print("TaskReadDwinCode running on core ");
    Serial.println(xPortGetCoreID());

    for (;;)
    {
        DwinReading dwinRData = dwinData.readDataFromDwin();
        if (dwinRData.errorFree)
        {
            if (DEBUG_MODE >= 2)
            {
                char tmp[40];
                sprintf(tmp, "Addr:\t0x%.4X\tValue:\t%i", dwinRData.vpAddr, dwinRData.Value);
                Serial.println(tmp);
            }
            processDwinData(dwinRData.Value, dwinRData.vpAddr);
        }
        delay(10);
    }
}

void setup()
{
    Serial.begin(115200, SERIAL_8N1, RXD0, TXD0);  // Integrated Serial
    Serial1.begin(115200, SERIAL_8N1, RXD1, TXD1); // Speeduino
    Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2); // DWIN Display

    xTaskCreatePinnedToCore(
        TaskReadDwinCode, /* Task function. */
        "TaskReadDwin",   /* name of task. */
        40000,            /* Stack size of task */
        NULL,             /* parameter of the task */
        1,                /* priority of the task */
        &TaskReadDwin,    /* Task handle to keep track of created task */
        0);               /* pin task to core 0 */

    if (DEBUG_MODE >= 1)
    {
        Serial.println("Serial Txd is on pin: " + String(TXD0));
        Serial.println("Serial Rxd is on pin: " + String(RXD0));
        Serial.println("Serial1 Txd is on pin: " + String(TXD1));
        Serial.println("Serial1 Rxd is on pin: " + String(RXD1));
        Serial.println("Serial2 Txd is on pin: " + String(TXD2));
        Serial.println("Serial2 Rxd is on pin: " + String(RXD2));
    }
    dwinData.resetToDefault(speeduinodDevice); // set facotry value to DWIN (this must be removed after implement a feature to save the values in DWIN memory)
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
                    bool resultDwin = dwinData.sendDataToDwin(speeduinodDevice[i].dwinValueVPaddr, resultGetFromSpeed.sValueByte1, resultGetFromSpeed.sValueByte2);
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
                        Serial.print(speeduinodDevice[i].freqRate);
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
