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
    {true, 5000, 0, 1, id000, 0x1000, 0x1004, 0x1008},
    {true, 10, 1, 1, id001, 0x1014, 0x1018, 0x101C},
    {false, 5000, 2, 1, id002, 0x1028, 0x102C, 0x1030},
    {false, 5000, 3, 1, id003, 0x103C, 0x1040, 0x1044},
    {true, 100, 4, 2, id004, 0x1050, 0x1054, 0x1058},
    {false, 5000, 6, 1, id005, 0x1064, 0x1068, 0x106C},
    {false, 5000, 7, 1, id006, 0x1078, 0x107C, 0x1080},
    {false, 5000, 8, 1, id007, 0x108C, 0x1090, 0x1094},
    {true, 5000, 9, 1, id008, 0x10A0, 0x10A4, 0x10A8},
    {false, 5000, 10, 1, id009, 0x10B4, 0x10B8, 0x10BC},
    {false, 5000, 11, 1, id010, 0x10C8, 0x10CC, 0x10D0},
    {false, 5000, 12, 1, id011, 0x10DC, 0x10E0, 0x10E4},
    {false, 5000, 13, 1, id012, 0x10F0, 0x10F4, 0x10F8},
    {true, 100, 14, 2, id013, 0x1104, 0x1108, 0x110C},
    {false, 5000, 16, 1, id014, 0x1118, 0x111C, 0x1120},
    {false, 5000, 17, 1, id015, 0x112C, 0x1130, 0x1134},
    {false, 5000, 18, 1, id016, 0x1140, 0x1144, 0x1148},
    {false, 5000, 19, 1, id017, 0x1154, 0x1158, 0x115C},
    {true, 100, 20, 2, id018, 0x1168, 0x116C, 0x1170},
    {false, 5000, 22, 1, id019, 0x117C, 0x1180, 0x1184},
    {false, 5000, 23, 1, id020, 0x1190, 0x1194, 0x1198},
    {false, 5000, 24, 1, id021, 0x11A4, 0x11A8, 0x11AC},
    {false, 5000, 25, 2, id022, 0x11B8, 0x11BC, 0x11C0},
    {false, 5000, 27, 2, id023, 0x11CC, 0x11D0, 0x11D4},
    {false, 5000, 29, 1, id024, 0x11E0, 0x11E4, 0x11E8},
    {false, 5000, 30, 1, id025, 0x11F4, 0x11F8, 0x11FC},
    {false, 5000, 31, 1, id026, 0x1208, 0x120C, 0x1210},
    {false, 5000, 32, 2, id027, 0x121C, 0x1220, 0x1224},
    {false, 5000, 34, 1, id028, 0x1230, 0x1234, 0x1238},
    {false, 5000, 35, 1, id029, 0x1244, 0x1248, 0x124C},
    {false, 5000, 36, 1, id030, 0x1258, 0x125C, 0x1260},
    {false, 5000, 37, 1, id031, 0x126C, 0x1270, 0x1274},
    {false, 5000, 38, 1, id032, 0x1280, 0x1284, 0x1288},
    {false, 5000, 39, 1, id033, 0x1294, 0x1298, 0x129C},
    {false, 5000, 40, 1, id034, 0x12A8, 0x12AC, 0x12B0},
    {false, 5000, 41, 2, id035, 0x12BC, 0x12C0, 0x12C4},
    {false, 5000, 43, 2, id036, 0x12D0, 0x12D4, 0x12D8},
    {false, 5000, 45, 2, id037, 0x12E4, 0x12E8, 0x12EC},
    {false, 5000, 47, 2, id038, 0x12F8, 0x12FC, 0x1300},
    {false, 5000, 49, 2, id039, 0x130C, 0x1310, 0x1314},
    {false, 5000, 51, 2, id040, 0x1320, 0x1324, 0x1328},
    {false, 5000, 53, 2, id041, 0x1334, 0x1338, 0x133C},
    {false, 5000, 55, 2, id042, 0x1348, 0x134C, 0x1350},
    {false, 5000, 57, 2, id043, 0x135C, 0x1360, 0x1364},
    {false, 5000, 59, 2, id044, 0x1370, 0x1374, 0x1378},
    {false, 5000, 61, 2, id045, 0x1384, 0x1388, 0x138C},
    {false, 5000, 63, 2, id046, 0x1398, 0x139C, 0x13A0},
    {false, 5000, 65, 2, id047, 0x13AC, 0x13B0, 0x13B4},
    {false, 5000, 67, 2, id048, 0x13C0, 0x13C4, 0x13C8},
    {false, 5000, 69, 2, id049, 0x13D4, 0x13D8, 0x13DC},
    {false, 5000, 71, 2, id050, 0x13E8, 0x13EC, 0x13F0},
    {false, 5000, 73, 1, id051, 0x13FC, 0x1400, 0x1404},
    {false, 5000, 74, 1, id052, 0x1410, 0x1414, 0x1418},
    {false, 5000, 75, 1, id053, 0x1424, 0x1428, 0x142C},
    {false, 5000, 76, 2, id054, 0x1438, 0x143C, 0x1440},
    {false, 5000, 78, 2, id055, 0x144C, 0x1450, 0x1454},
    {false, 5000, 80, 2, id056, 0x1460, 0x1464, 0x1468},
    {false, 5000, 82, 1, id057, 0x1474, 0x1478, 0x147C},
    {false, 5000, 83, 1, id058, 0x1488, 0x148C, 0x1490},
    {false, 5000, 84, 2, id059, 0x149C, 0x14A0, 0x14A4},
    {false, 5000, 86, 2, id060, 0x14B0, 0x14B4, 0x14B8},
    {false, 5000, 88, 2, id061, 0x14C4, 0x14C8, 0x14CC},
    {false, 5000, 90, 1, id062, 0x14D8, 0x14DC, 0x14E0},
    {false, 5000, 91, 1, id063, 0x14EC, 0x14F0, 0x14F4},
    {false, 5000, 92, 1, id064, 0x1500, 0x1504, 0x1508},
    {false, 5000, 93, 1, id065, 0x1514, 0x1518, 0x151C},
    {false, 5000, 94, 1, id066, 0x1528, 0x152C, 0x1530},
    {false, 5000, 95, 1, id067, 0x153C, 0x1540, 0x1544},
    {false, 5000, 96, 2, id068, 0x1550, 0x1554, 0x1558},
    {false, 5000, 98, 1, id069, 0x1564, 0x1568, 0x156C},
    {false, 5000, 99, 1, id070, 0x1578, 0x157C, 0x1580},
    {false, 5000, 100, 2, id071, 0x158C, 0x1590, 0x1594},
    {false, 5000, 102, 1, id072, 0x15A0, 0x15A4, 0x15A8},
    {false, 5000, 103, 1, id073, 0x15B4, 0x15B8, 0x15BC},
    {false, 5000, 104, 1, id074, 0x15C8, 0x15CC, 0x15D0},
    {false, 5000, 105, 1, id075, 0x15DC, 0x15E0, 0x15E4},
    {false, 5000, 106, 1, id076, 0x15F0, 0x15F4, 0x15F8},
    {false, 5000, 107, 1, id077, 0x1604, 0x1608, 0x160C},
    {false, 5000, 108, 1, id078, 0x1618, 0x161C, 0x1620},
    {false, 5000, 109, 1, id079, 0x162C, 0x1630, 0x1634},
    {false, 5000, 110, 1, id080, 0x1640, 0x1644, 0x1648},
    {false, 5000, 111, 1, id081, 0x1654, 0x1658, 0x165C},
    {false, 5000, 112, 1, id082, 0x1668, 0x166C, 0x1670},
    {false, 5000, 113, 1, id083, 0x167C, 0x1680, 0x1684},
    {false, 5000, 114, 1, id084, 0x1690, 0x1694, 0x1698},
    {false, 5000, 115, 1, id085, 0x16A4, 0x16A8, 0x16AC},
    {false, 5000, 116, 1, id086, 0x16B8, 0x16BC, 0x16C0},
    {false, 5000, 117, 1, id087, 0x16CC, 0x16D0, 0x16D4},
    {false, 5000, 118, 1, id088, 0x16E0, 0x16E4, 0x16E8}

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