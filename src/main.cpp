#include "arduino.h"
#include "defines.h"
#include "speedvars.h"
#include "speeduinodata.h"
#include "dwindata.h"
#include "Preferences.h"
#include "nvs_flash.h"

SpeeduinoData SData(&Serial1);
DwinData dwinData(&Serial2);

long lastReads[NUMBER_OF_SPEEDUINO_AVAILABLE_DEVICES];

TaskHandle_t TaskReadDwin;

Preferences storedFreq;
Preferences storedToggle;

void storeDataToMem(int i)
{
    // store freq and toggle to non-volatile memory to survide reboots
    // putBool(const char* key, const bool value)
    // putUShort(const char* key, uint16_t value)
    char ii[3];
    String str;
    str = String(i);
    str.toCharArray(ii, 3);

    storedToggle.putBool(ii, speeduinodDeviceToggle[i]);
    storedFreq.putUShort(ii, speeduinodDeviceFreq[i]);
}

void restoreDataFomMem()
{
    // restore freq and toggle from non-volatile memory to local vars
    for (int i = 0; i < NUMBER_OF_SPEEDUINO_AVAILABLE_DEVICES; i++)
    {
        char ii[3];
        String str;
        str = String(i);
        str.toCharArray(ii, 3);

        speeduinodDeviceToggle[i] = storedToggle.getBool(ii, speeduinodDeviceFactoryDefaults[i].selected); // getBool(const char* key, const bool defaultValue)
        speeduinodDeviceFreq[i] = storedFreq.getUShort(ii, speeduinodDeviceFactoryDefaults[i].freqRate);   // getUShort(const char* key, const uint16_t defaultValue)
    }
}

void updSpeeduinoVar(int16_t value, int16_t addr)
{
    for (int i = 0; i < NUMBER_OF_SPEEDUINO_AVAILABLE_DEVICES; i++)
    {
        if (speeduinodDeviceFactoryDefaults[i].dwinFreqVPaddr == addr)
        {
            // Serial.println("** faz update à variável ** freq");
            speeduinodDeviceFreq[i] = value;
            storeDataToMem(i);
            break;
        }
        if (speeduinodDeviceFactoryDefaults[i].dwinToggleVPaddr == addr)
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
                dwinData.sendDataToDwin(speeduinodDeviceFactoryDefaults[i].dwinValueVPaddr, 0, 0); // sets the value to zero in DWIN
            }
            speeduinodDeviceToggle[i] = bValue;
            storeDataToMem(i);
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

void factoryResetRebootEsp(boolean reset)
{
    if (reset)
    {
        nvs_flash_erase(); // erase the NVS partition and...
        nvs_flash_init();  // initialize the NVS partition.
    }
    ESP.restart();
}

void processDwinData(int16_t value, int16_t addr)
{
    if (addr == 9000 && value == 1)
    {
        // reboot ESP32
        factoryResetRebootEsp(false);
    }
    else if (addr == 9010 && value == 1)
    {
        // factory reset the values
        /* Replaced by the nvs_flash_erase() + nvs_flash_init() + ESP.restart()
        // Requires further tests to check if works as expected
        for (int i = 0; i < NUMBER_OF_SPEEDUINO_AVAILABLE_DEVICES; i++)
        {
            speeduinodDeviceFreq[i] = speeduinodDeviceFactoryDefaults[i].freqRate;
            speeduinodDeviceToggle[i] = speeduinodDeviceFactoryDefaults[i].selected;
        }
        dwinData.resetToDefault(speeduinodDeviceFactoryDefaults, speeduinodDeviceFreq, speeduinodDeviceToggle);
        */
        factoryResetRebootEsp(true);
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
    Serial.println();

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
    // Open Preferences with freq and toggle namespaces. Each application module, library, etc
    // has to use a namespace name to prevent key name collisions. We will open storage in
    // RW-mode (second parameter has to be false).
    // Note: Namespace name is limited to 15 chars.
    storedFreq.begin("freq", false);
    storedToggle.begin("toggle", false);

    restoreDataFomMem();
    dwinData.resetToDefault(speeduinodDeviceFactoryDefaults, speeduinodDeviceFreq, speeduinodDeviceToggle); // set facotry value to DWIN (this must be removed after implement a feature to save the values in DWIN memory)
}

void loop()
{
    char buffer[200];
    char sValueName[80];

    for (int i = 0; i < NUMBER_OF_SPEEDUINO_AVAILABLE_DEVICES; i++)
    {
        if (speeduinodDeviceToggle[i])
        {
            if ((millis() - lastReads[i]) > speeduinodDeviceFreq[i])
            {
                memset(sValueName, 0, sizeof sValueName); // filling the array with meaningless values
                memset(buffer, 0, sizeof buffer);         // filling the array with meaningless values

                SpeeduinoResult resultGetFromSpeed = SData.getDataFromLocation(speeduinodDeviceFactoryDefaults[i].lowByte, speeduinodDeviceFactoryDefaults[i].numBytes);
                if (resultGetFromSpeed.errorFree)
                {
                    bool resultDwin = dwinData.sendDataToDwin(speeduinodDeviceFactoryDefaults[i].dwinValueVPaddr, resultGetFromSpeed.sValueByte1, resultGetFromSpeed.sValueByte2);
                    if (resultDwin)
                    {
                        lastReads[i] = millis();
                    }
                    if (DEBUG_MODE >= 1)
                    {
                        long value = resultGetFromSpeed.sValue;
                        strcpy_P(sValueName, speeduinodDeviceFactoryDefaults[i].name);
                        Serial.print("+>\t");
                        Serial.print(value);
                        Serial.print("\t+<\t");
                        Serial.print(i);
                        Serial.print("\t|\t");
                        Serial.print(speeduinodDeviceFreq[i]);
                        Serial.print("\t|\t");
                        Serial.print(speeduinodDeviceFactoryDefaults[i].lowByte);
                        Serial.print("\t");
                        Serial.print(speeduinodDeviceFactoryDefaults[i].numBytes);
                        Serial.print("\t|\t");
                        Serial.println(sValueName);
                    }
                }
            }
        }
    }
}
