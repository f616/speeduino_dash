#ifndef __SPEEDVARS_H__
#define __SPEEDVARS_H__

#include <Arduino.h>
#include "structures.h"
#include "defines.h"

const char id000[] PROGMEM = "secl";
const char id001[] PROGMEM = "status1";
const char id002[] PROGMEM = "engine";
const char id003[] PROGMEM = "dwell";
const char id004[] PROGMEM = "MAP";
const char id005[] PROGMEM = "IAT";
const char id006[] PROGMEM = "coolantTemp";
const char id007[] PROGMEM = "batCorrection";
const char id008[] PROGMEM = "batVoltage";
const char id009[] PROGMEM = "O2";
const char id010[] PROGMEM = "egoCorrection";
const char id011[] PROGMEM = "iatCorrection";
const char id012[] PROGMEM = "wueCorrection";
const char id013[] PROGMEM = "RPM";
const char id014[] PROGMEM = "TAEamount";
const char id015[] PROGMEM = "corrections";
const char id016[] PROGMEM = "VE";
const char id017[] PROGMEM = "afrTarget";
const char id018[] PROGMEM = "PW1";
const char id019[] PROGMEM = "tpsDOT";
const char id020[] PROGMEM = "advance";
const char id021[] PROGMEM = "TPS";
const char id022[] PROGMEM = "loopsPerSecond";
const char id023[] PROGMEM = "freeRAM";
const char id024[] PROGMEM = "boostTarget";
const char id025[] PROGMEM = "boostDuty";
const char id026[] PROGMEM = "spark";
const char id027[] PROGMEM = "rpmDOT";
const char id028[] PROGMEM = "ethanolPct";
const char id029[] PROGMEM = "flexCorrection";
const char id030[] PROGMEM = "flexIgnCorrection";
const char id031[] PROGMEM = "idleLoad";
const char id032[] PROGMEM = "testOutputs";
const char id033[] PROGMEM = "O2_2";
const char id034[] PROGMEM = "baro";
const char id035[] PROGMEM = "canin0";
const char id036[] PROGMEM = "canin1";
const char id037[] PROGMEM = "canin2";
const char id038[] PROGMEM = "canin3";
const char id039[] PROGMEM = "canin4";
const char id040[] PROGMEM = "canin5";
const char id041[] PROGMEM = "canin6";
const char id042[] PROGMEM = "canin7";
const char id043[] PROGMEM = "canin8";
const char id044[] PROGMEM = "canin9";
const char id045[] PROGMEM = "canin10";
const char id046[] PROGMEM = "canin11";
const char id047[] PROGMEM = "canin12";
const char id048[] PROGMEM = "canin13";
const char id049[] PROGMEM = "canin14";
const char id050[] PROGMEM = "canin15";
const char id051[] PROGMEM = "tpsADC";
const char id052[] PROGMEM = "getNextError";
const char id053[] PROGMEM = "launchCorrection";
const char id054[] PROGMEM = "PW2";
const char id055[] PROGMEM = "PW3";
const char id056[] PROGMEM = "PW4";
const char id057[] PROGMEM = "status3";
const char id058[] PROGMEM = "engineProtectStatus";
const char id059[] PROGMEM = "fuelLoad";
const char id060[] PROGMEM = "ignLoad";
const char id061[] PROGMEM = "injAngle";
const char id062[] PROGMEM = "idleDuty";
const char id063[] PROGMEM = "CLIdleTarget";
const char id064[] PROGMEM = "mapDOT";
const char id065[] PROGMEM = "vvt1Angle";
const char id066[] PROGMEM = "vvt1TargetAngle";
const char id067[] PROGMEM = "vvt1Duty";
const char id068[] PROGMEM = "flexBoostCorrection";
const char id069[] PROGMEM = "baroCorrection";
const char id070[] PROGMEM = "ASEValue";
const char id071[] PROGMEM = "vss";
const char id072[] PROGMEM = "gear";
const char id073[] PROGMEM = "fuelPressure";
const char id074[] PROGMEM = "oilPressure";
const char id075[] PROGMEM = "wmiPW";
const char id076[] PROGMEM = "status4";
const char id077[] PROGMEM = "vvt2Angle";
const char id078[] PROGMEM = "vvt2TargetAngle";
const char id079[] PROGMEM = "vvt2Duty";
const char id080[] PROGMEM = "outputsStatus";
const char id081[] PROGMEM = "fuelTemp";
const char id082[] PROGMEM = "fuelTempCorrection";
const char id083[] PROGMEM = "VE1";
const char id084[] PROGMEM = "VE2";
const char id085[] PROGMEM = "advance1";
const char id086[] PROGMEM = "advance2";
const char id087[] PROGMEM = "nitrousStatus";
const char id088[] PROGMEM = "SDStatus";

/* Speeduino available variables through Serial IO Interface */
speeduinoDataList speeduinodDeviceFactoryDefaults[NUMBER_OF_SPEEDUINO_AVAILABLE_DEVICES + 1] = {
    // Send to DWIN
    // enabled, update freq, Speeduino LowByte, Speeduino NumberOfBytes, Name, DWIN value VPaddr, freq VPaddr, toggle VPaddr
    {true, 5000, 0, 1, id000, 0x0100, 0x0104, 0x0108},
    {true, 10, 1, 1, id001, 0x0114, 0x0118, 0x011C},
    {false, 5000, 2, 1, id002, 0x0128, 0x012C, 0x0130},
    {false, 5000, 3, 1, id003, 0x013C, 0x0140, 0x0144},
    {false, 100, 4, 2, id004, 0x0150, 0x0154, 0x0158},
    {false, 5000, 6, 1, id005, 0x0164, 0x0168, 0x016C},
    {false, 5000, 7, 1, id006, 0x0178, 0x017C, 0x0180},
    {false, 5000, 8, 1, id007, 0x018C, 0x0190, 0x0194},
    {false, 5000, 9, 1, id008, 0x01A0, 0x01A4, 0x01A8},
    {false, 5000, 10, 1, id009, 0x01B4, 0x01B8, 0x01BC},
    {false, 5000, 11, 1, id010, 0x01C8, 0x01CC, 0x01D0},
    {false, 5000, 12, 1, id011, 0x01DC, 0x01E0, 0x01E4},
    {false, 5000, 13, 1, id012, 0x01F0, 0x01F4, 0x01F8},
    {true, 100, 14, 2, id013, 0x0204, 0x0208, 0x020C},
    {false, 5000, 16, 1, id014, 0x0218, 0x021C, 0x0220},
    {false, 5000, 17, 1, id015, 0x022C, 0x0230, 0x0234},
    {false, 5000, 18, 1, id016, 0x0240, 0x0244, 0x0248},
    {false, 5000, 19, 1, id017, 0x0254, 0x0258, 0x025C},
    {false, 100, 20, 2, id018, 0x0268, 0x026C, 0x0270},
    {false, 5000, 22, 1, id019, 0x027C, 0x0280, 0x0284},
    {false, 5000, 23, 1, id020, 0x0290, 0x0294, 0x0298},
    {false, 5000, 24, 1, id021, 0x02A4, 0x02A8, 0x02AC},
    {false, 5000, 25, 2, id022, 0x02B8, 0x02BC, 0x02C0},
    {false, 5000, 27, 2, id023, 0x02CC, 0x02D0, 0x02D4},
    {false, 5000, 29, 1, id024, 0x02E0, 0x02E4, 0x02E8},
    {false, 5000, 30, 1, id025, 0x02F4, 0x02F8, 0x02FC},
    {false, 5000, 31, 1, id026, 0x0308, 0x030C, 0x0310},
    {false, 5000, 32, 2, id027, 0x031C, 0x0320, 0x0324},
    {false, 5000, 34, 1, id028, 0x0330, 0x0334, 0x0338},
    {false, 5000, 35, 1, id029, 0x0344, 0x0348, 0x034C},
    {false, 5000, 36, 1, id030, 0x0358, 0x035C, 0x0360},
    {false, 5000, 37, 1, id031, 0x036C, 0x0370, 0x0374},
    {false, 5000, 38, 1, id032, 0x0380, 0x0384, 0x0388},
    {false, 5000, 39, 1, id033, 0x0394, 0x0398, 0x039C},
    {false, 5000, 40, 1, id034, 0x03A8, 0x03AC, 0x03B0},
    {false, 5000, 41, 2, id035, 0x03BC, 0x03C0, 0x03C4},
    {false, 5000, 43, 2, id036, 0x03D0, 0x03D4, 0x03D8},
    {false, 5000, 45, 2, id037, 0x03E4, 0x03E8, 0x03EC},
    {false, 5000, 47, 2, id038, 0x03F8, 0x03FC, 0x0400},
    {false, 5000, 49, 2, id039, 0x040C, 0x0410, 0x0414},
    {false, 5000, 51, 2, id040, 0x0420, 0x0424, 0x0428},
    {false, 5000, 53, 2, id041, 0x0434, 0x0438, 0x043C},
    {false, 5000, 55, 2, id042, 0x0448, 0x044C, 0x0450},
    {false, 5000, 57, 2, id043, 0x045C, 0x0460, 0x0464},
    {false, 5000, 59, 2, id044, 0x0470, 0x0474, 0x0478},
    {false, 5000, 61, 2, id045, 0x0484, 0x0488, 0x048C},
    {false, 5000, 63, 2, id046, 0x0498, 0x049C, 0x04A0},
    {false, 5000, 65, 2, id047, 0x04AC, 0x04B0, 0x04B4},
    {false, 5000, 67, 2, id048, 0x04C0, 0x04C4, 0x04C8},
    {false, 5000, 69, 2, id049, 0x04D4, 0x04D8, 0x04DC},
    {false, 5000, 71, 2, id050, 0x04E8, 0x04EC, 0x04F0},
    {false, 5000, 73, 1, id051, 0x04FC, 0x0500, 0x0504},
    {false, 5000, 74, 1, id052, 0x0510, 0x0514, 0x0518},
    {false, 5000, 75, 1, id053, 0x0524, 0x0528, 0x052C},
    {false, 5000, 76, 2, id054, 0x0538, 0x053C, 0x0540},
    {false, 5000, 78, 2, id055, 0x054C, 0x0550, 0x0554},
    {false, 5000, 80, 2, id056, 0x0560, 0x0564, 0x0568},
    {false, 5000, 82, 1, id057, 0x0574, 0x0578, 0x057C},
    {false, 5000, 83, 1, id058, 0x0588, 0x058C, 0x0590},
    {false, 5000, 84, 2, id059, 0x059C, 0x05A0, 0x05A4},
    {false, 5000, 86, 2, id060, 0x05B0, 0x05B4, 0x05B8},
    {false, 5000, 88, 2, id061, 0x05C4, 0x05C8, 0x05CC},
    {false, 5000, 90, 1, id062, 0x05D8, 0x05DC, 0x05E0},
    {false, 5000, 91, 1, id063, 0x05EC, 0x05F0, 0x05F4},
    {false, 5000, 92, 1, id064, 0x0600, 0x0604, 0x0608},
    {false, 5000, 93, 1, id065, 0x0614, 0x0618, 0x061C},
    {false, 5000, 94, 1, id066, 0x0628, 0x062C, 0x0630},
    {false, 5000, 95, 1, id067, 0x063C, 0x0640, 0x0644},
    {false, 5000, 96, 2, id068, 0x0650, 0x0654, 0x0658},
    {false, 5000, 98, 1, id069, 0x0664, 0x0668, 0x066C},
    {false, 5000, 99, 1, id070, 0x0678, 0x067C, 0x0680},
    {false, 5000, 100, 2, id071, 0x068C, 0x0690, 0x0694},
    {false, 5000, 102, 1, id072, 0x06A0, 0x06A4, 0x06A8},
    {false, 5000, 103, 1, id073, 0x06B4, 0x06B8, 0x06BC},
    {false, 5000, 104, 1, id074, 0x06C8, 0x06CC, 0x06D0},
    {false, 5000, 105, 1, id075, 0x06DC, 0x06E0, 0x06E4},
    {false, 5000, 106, 1, id076, 0x06F0, 0x06F4, 0x06F8},
    {false, 5000, 107, 1, id077, 0x0704, 0x0708, 0x070C},
    {false, 5000, 108, 1, id078, 0x0718, 0x071C, 0x0720},
    {false, 5000, 109, 1, id079, 0x072C, 0x0730, 0x0734},
    {false, 5000, 110, 1, id080, 0x0740, 0x0744, 0x0748},
    {false, 5000, 111, 1, id081, 0x0754, 0x0758, 0x075C},
    {false, 5000, 112, 1, id082, 0x0768, 0x076C, 0x0770},
    {false, 5000, 113, 1, id083, 0x077C, 0x0780, 0x0784},
    {false, 5000, 114, 1, id084, 0x0790, 0x0794, 0x0798},
    {false, 5000, 115, 1, id085, 0x07A4, 0x07A8, 0x07AC},
    {false, 5000, 116, 1, id086, 0x07B8, 0x07BC, 0x07C0},
    {false, 5000, 117, 1, id087, 0x07CC, 0x07D0, 0x07D4},
    {false, 5000, 118, 1, id088, 0x07E0, 0x07E4, 0x07E8}

};

boolean speeduinodDeviceToggle[NUMBER_OF_SPEEDUINO_AVAILABLE_DEVICES + 1] = {};
uint16_t speeduinodDeviceFreq[NUMBER_OF_SPEEDUINO_AVAILABLE_DEVICES + 1] = {};

#endif

/*
Location and length from https://wiki.speeduino.com/en/Secondary_Serial_IO_interface

lowByte	numBytes	name	                    desc
0	    1	        secl	                    secl is simply a counter that increments each second
1	    1	        status1	                    Status1 Bitfield(was squirt): inj1Status(0), inj2Status(1),inj3Status(2), inj4Status(3), DFCOOn(4), boostCutFuel(5), toothLog1Ready(6), toothLog2Ready(7)
2	    1	        engine	                    Engine Status Bitfield: running(0), crank(1), ase(2), warmup(3), tpsacden(5), mapaccden(7)
3	    1	        dwell	                    Dwell in ms * 10
4	    2	        MAP	                        MAP
6	    1	        IAT                         MAT + CALIBRATION_TEMPERATURE_OFFSET (40)
7	    1	        coolantTemp                 Coolant ADC + CALIBRATION_TEMPERATURE_OFFSET (40)
8	    1	        batCorrection	            Battery voltage correction (%)
9	    1	        batVoltage	                Battery voltage divided by 10 in V
10	    1	        O2	                        Primary O2
11	    1	        egoCorrection	            Exhaust gas correction (%)
12	    1	        iatCorrection	            Air temperature Correction (%)
13	    1	        wueCorrection	            Warmup enrichment (%)
14	    2	        RPM	                        RPM
16	    1	        TAEamount	                Acceleration enrichment (%)
17	    1	        corrections	                Total GammaE (%)
18	    1	        VE	                        Current VE 1 (%)
19	    1	        afrTarget	                Chosen afr target
20	    2	        PW1	                        Pulsewidth 1 multiplied by 10 in ms. Have to convert from uS to mS.
22	    1	        tpsDOT	                    TPS DOT
23	    1	        advance	                    Spark advance
24	    1	        TPS	                        TPS (0% to 100%)
25	    2	        loopsPerSecond	            Loops per second
27	    2	        freeRAM	                    Free RAM
29	    1	        boostTarget	                Target boost pressure
30	    1	        boostDuty	                PWM boost dutycycle
31	    1	        spark	                    Spark related bitfield: launchHard(0), launchSoft(1), hardLimitOn(2), softLimitOn(3), boostCutSpark(4), error(5), idleControlOn(6), sync(7)
32	    2	        rpmDOT	                    RPM DOT
34	    1	        ethanolPct	                Flex sensor value (or 0 if not used)
35	    1	        flexCorrection	            Flex fuel correction (% above or below 100)
36	    1	        flexIgnCorrection	        Ignition correction (Increased degrees of advance) for flex fuel
37	    1	        idleLoad	                Idle load
38	    1	        testOutputs	                Test outputs bitfield: testEnabled(0), testActive(1)
39	    1	        O2_2	                    Secondary O2
40	    1	        baro	                    Barometer value
41	    2	        canin0
43	    2	        canin1
45	    2	        canin2
47	    2	        canin3
49	    2	        canin4
51	    2	        canin5
53	    2	        canin6
55	    2	        canin7
57	    2	        canin8
59	    2	        canin9
61	    2	        canin10
63	    2	        canin11
65	    2	        canin12
67	    2	        canin13
69	    2	        canin14
71	    2	        canin15
73	    1	        tpsADC	                    TPS (Raw 0-255)
74	    1	        getNextError	            Error codes: errorNum(0:1), currentError(2:7)
75	    1	        launchCorrection
76	    2	        PW2	                        Pulsewidth 2 multiplied by 10 in ms. Have to convert from uS to mS.
78	    2	        PW3	                        Pulsewidth 3 multiplied by 10 in ms. Have to convert from uS to mS.
80	    2	        PW4	                        Pulsewidth 4 multiplied by 10 in ms. Have to convert from uS to mS.
82	    1	        status3	                    resentLockOn(0), nitrousOn(1), fuel2Active(2), vssRefresh(3), halfSync(4), nSquirts(6:7)
83	    1	        engineProtectStatus	        RPM(0), MAP(1), OIL(2), AFR(3), Unused(4:7)
84	    2	        fuelLoad
86	    2	        ignLoad
88	    2	        injAngle
90	    1	        idleDuty
91	    1	        CLIdleTarget	            closed loop idle target
92	    1	        mapDOT	                    rate of change of the map
93	    1	        vvt1Angle
94	    1	        vvt1TargetAngle
95	    1	        vvt1Duty
96	    2	        flexBoostCorrection
98	    1	        baroCorrection
99	    1	        ASEValue	                Current ASE (%)
100	    2	        vss	                        speed reading from the speed sensor
102	    1	        gear
103	    1	        fuelPressure
104	    1	        oilPressure
105	    1	        wmiPW
106	    1	        status4	                    wmiEmptyBit(0), vvt1Error(1), vvt2Error(2), UnusedBits(3:7)
107	    1	        vvt2Angle
108	    1	        vvt2TargetAngle
109	    1	        vvt2Duty
110	    1	        outputsStatus
111	    1	        fuelTemp                    Fuel temperature from flex sensor + +CALIBRATION_TEMPERATURE_OFFSET
112	    1	        fuelTempCorrection	        Fuel temperature Correction (%)
113	    1	        VE1	VE 1 (%)
114	    1	        VE2	VE 2 (%)
115	    1	        advance1	                Advance 1
116	    1	        advance2	                Advance 2
117	    1	        nitrousStatus
118	    1	        SDStatus	                SD card status

*/