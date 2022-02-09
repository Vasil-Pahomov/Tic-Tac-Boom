EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MY:OLED1.3SPI U2
U 1 1 60786F80
P 2900 5900
F 0 "U2" H 3228 6204 50  0000 L CNN
F 1 "OLED1.3SPI" H 3228 6113 50  0000 L CNN
F 2 "MY:Oled1.3SPI" H 2900 5900 50  0001 C CNN
F 3 "" H 2900 5900 50  0001 C CNN
	1    2900 5900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 607880D2
P 5100 4700
F 0 "#PWR06" H 5100 4450 50  0001 C CNN
F 1 "GND" H 5105 4527 50  0000 C CNN
F 2 "" H 5100 4700 50  0001 C CNN
F 3 "" H 5100 4700 50  0001 C CNN
	1    5100 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 4350 4900 4450
Wire Wire Line
	4900 4350 5100 4350
Wire Wire Line
	5100 4350 5100 4700
$Comp
L power:GND #PWR02
U 1 1 607895F0
P 2150 5500
F 0 "#PWR02" H 2150 5250 50  0001 C CNN
F 1 "GND" H 2155 5327 50  0000 C CNN
F 2 "" H 2150 5500 50  0001 C CNN
F 3 "" H 2150 5500 50  0001 C CNN
	1    2150 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 5500 2150 5300
Wire Wire Line
	2150 5300 2450 5300
Wire Wire Line
	2650 3750 3500 3750
Wire Wire Line
	2650 3750 2650 5300
Wire Wire Line
	2750 3950 3500 3950
Wire Wire Line
	2750 3950 2750 5300
Wire Wire Line
	3050 4050 3500 4050
Wire Wire Line
	3050 4050 3050 5300
Wire Wire Line
	2850 5300 2850 5150
Wire Wire Line
	2850 5150 5400 5150
Wire Wire Line
	5400 5150 5400 4050
Wire Wire Line
	2950 5300 2950 5250
Wire Wire Line
	2950 5250 5550 5250
Wire Wire Line
	5550 5250 5550 3950
$Comp
L Connector:Conn_01x02_Female J1
U 1 1 607923D6
P 5850 3150
F 0 "J1" H 5878 3126 50  0000 L CNN
F 1 "Button" H 5878 3035 50  0000 L CNN
F 2 "TestPoint:TestPoint_2Pads_Pitch2.54mm_Drill0.8mm" H 5850 3150 50  0001 C CNN
F 3 "~" H 5850 3150 50  0001 C CNN
	1    5850 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR07
U 1 1 60793541
P 5650 3250
F 0 "#PWR07" H 5650 3000 50  0001 C CNN
F 1 "GND" H 5655 3077 50  0000 C CNN
F 2 "" H 5650 3250 50  0001 C CNN
F 3 "" H 5650 3250 50  0001 C CNN
	1    5650 3250
	1    0    0    -1  
$EndComp
$Comp
L MY:StepUp5V U3
U 1 1 60793DE5
P 3800 1650
F 0 "U3" H 3825 2115 50  0000 C CNN
F 1 "StepUp5V" H 3825 2024 50  0000 C CNN
F 2 "MY:StepUp5V" H 3800 1650 50  0001 C CNN
F 3 "" H 3800 1650 50  0001 C CNN
	1    3800 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 1350 1950 1350
$Comp
L power:GND #PWR01
U 1 1 607982BD
P 2150 1350
F 0 "#PWR01" H 2150 1100 50  0001 C CNN
F 1 "GND" H 2155 1177 50  0000 C CNN
F 2 "" H 2150 1350 50  0001 C CNN
F 3 "" H 2150 1350 50  0001 C CNN
	1    2150 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NPN_ECB Q1
U 1 1 6079944F
P 2800 1200
F 0 "Q1" H 2991 1246 50  0000 L CNN
F 1 "Q_NPN_ECB" H 2991 1155 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220F-3_Vertical" H 3000 1300 50  0001 C CNN
F 3 "~" H 2800 1200 50  0001 C CNN
	1    2800 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 6079A6C5
P 2600 1350
F 0 "R1" H 2670 1396 50  0000 L CNN
F 1 "22k" H 2670 1305 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2530 1350 50  0001 C CNN
F 3 "~" H 2600 1350 50  0001 C CNN
	1    2600 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 6079B0A5
P 2600 1500
F 0 "#PWR03" H 2600 1250 50  0001 C CNN
F 1 "GND" H 2605 1327 50  0000 C CNN
F 2 "" H 2600 1500 50  0001 C CNN
F 3 "" H 2600 1500 50  0001 C CNN
	1    2600 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 4050 4900 4050
Wire Wire Line
	4900 3950 5550 3950
$Comp
L Device:Buzzer BZ1
U 1 1 607A21DD
P 7150 4550
F 0 "BZ1" H 7302 4579 50  0000 L CNN
F 1 "Buzzer" H 7302 4488 50  0000 L CNN
F 2 "TestPoint:TestPoint_2Pads_Pitch2.54mm_Drill0.8mm" V 7125 4650 50  0001 C CNN
F 3 "~" V 7125 4650 50  0001 C CNN
	1    7150 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 3850 4900 3850
Wire Wire Line
	1950 1000 2600 1000
Wire Wire Line
	2900 1400 2900 1450
Wire Wire Line
	2900 1450 3250 1450
$Comp
L power:GND #PWR04
U 1 1 607A77A4
P 3250 1800
F 0 "#PWR04" H 3250 1550 50  0001 C CNN
F 1 "GND" H 3255 1627 50  0000 C CNN
F 2 "" H 3250 1800 50  0001 C CNN
F 3 "" H 3250 1800 50  0001 C CNN
	1    3250 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 1200 2600 1200
Connection ~ 2600 1200
Wire Wire Line
	2400 1200 2400 2050
Wire Wire Line
	5250 2050 5250 3350
Wire Wire Line
	5250 3350 4900 3350
$Comp
L Connector:Conn_01x02_Female J2
U 1 1 607C4C0B
P 6700 3550
F 0 "J2" H 6728 3526 50  0000 L CNN
F 1 "Button_LED" H 6728 3435 50  0000 L CNN
F 2 "TestPoint:TestPoint_2Pads_Pitch2.54mm_Drill0.8mm" H 6700 3550 50  0001 C CNN
F 3 "~" H 6700 3550 50  0001 C CNN
	1    6700 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 607C6C56
P 6500 3650
F 0 "#PWR08" H 6500 3400 50  0001 C CNN
F 1 "GND" H 6505 3477 50  0000 C CNN
F 2 "" H 6500 3650 50  0001 C CNN
F 3 "" H 6500 3650 50  0001 C CNN
	1    6500 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 2050 5250 2050
$Comp
L Device:Q_PNP_ECB Q3
U 1 1 607C7E0C
P 6950 4250
F 0 "Q3" H 7141 4296 50  0000 L CNN
F 1 "Q_NPN_ECB" H 7141 4205 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 7150 4350 50  0001 C CNN
F 3 "~" H 6950 4250 50  0001 C CNN
	1    6950 4250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR09
U 1 1 607A377D
P 7050 4650
F 0 "#PWR09" H 7050 4400 50  0001 C CNN
F 1 "GND" H 7055 4477 50  0000 C CNN
F 2 "" H 7050 4650 50  0001 C CNN
F 3 "" H 7050 4650 50  0001 C CNN
	1    7050 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 3850 6000 4250
Wire Wire Line
	6000 4250 6750 4250
Wire Wire Line
	2550 5300 2550 5000
Wire Wire Line
	2550 5000 8900 5000
$Comp
L power:GND #PWR05
U 1 1 607CDF37
P 4400 1800
F 0 "#PWR05" H 4400 1550 50  0001 C CNN
F 1 "GND" H 4405 1627 50  0000 C CNN
F 2 "" H 4400 1800 50  0001 C CNN
F 3 "" H 4400 1800 50  0001 C CNN
	1    4400 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 3450 5350 3450
Wire Wire Line
	5350 3150 5650 3150
Wire Wire Line
	5350 3150 5350 3450
$Comp
L Device:R R2
U 1 1 607C35CF
P 6500 3400
F 0 "R2" V 6293 3400 50  0000 C CNN
F 1 "R" V 6384 3400 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6430 3400 50  0001 C CNN
F 3 "~" H 6500 3400 50  0001 C CNN
	1    6500 3400
	-1   0    0    1   
$EndComp
Wire Wire Line
	4900 3550 6200 3550
Wire Wire Line
	2600 1000 2600 650 
Wire Wire Line
	2600 650  5050 650 
Wire Wire Line
	5050 2350 4900 2350
Connection ~ 2600 1000
Wire Wire Line
	2600 1000 2900 1000
Wire Wire Line
	4400 1450 6500 1450
$Comp
L Device:Q_NPN_CBE Q2
U 1 1 6082DA99
P 6400 3050
F 0 "Q2" H 6591 3096 50  0000 L CNN
F 1 "Q_NPN_CBE" H 6591 3005 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92" H 6600 3150 50  0001 C CNN
F 3 "~" H 6400 3050 50  0001 C CNN
	1    6400 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 3050 6200 3550
Wire Wire Line
	6500 2850 6500 1450
Connection ~ 6500 1450
Wire Wire Line
	6500 1450 7050 1450
Wire Wire Line
	7050 1450 7050 4050
$Comp
L Regulator_Linear:ADP7142AUJZ-3.3 U5
U 1 1 616D7253
P 7900 1550
F 0 "U5" H 7900 1917 50  0000 C CNN
F 1 "ADP7142AUJZ-3.3" H 7900 1826 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TSOT-23-5" H 7900 1150 50  0001 C CIN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/ADP7142.pdf" H 7900 1050 50  0001 C CNN
	1    7900 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 1450 7350 1450
Connection ~ 7050 1450
Wire Wire Line
	8300 1450 8900 1450
Wire Wire Line
	8900 1450 8900 5000
$Comp
L power:GND #PWR010
U 1 1 616DC059
P 7900 1850
F 0 "#PWR010" H 7900 1600 50  0001 C CNN
F 1 "GND" H 7905 1677 50  0000 C CNN
F 2 "" H 7900 1850 50  0001 C CNN
F 3 "" H 7900 1850 50  0001 C CNN
	1    7900 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 1450 7350 1650
Wire Wire Line
	7350 1650 7500 1650
Connection ~ 7350 1450
Wire Wire Line
	7350 1450 7500 1450
$Comp
L Device:R_POT RV1
U 1 1 619B6141
P 2800 2900
F 0 "RV1" H 2731 2946 50  0000 R CNN
F 1 "R_POT" H 2731 2855 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3386C_Horizontal" H 2800 2900 50  0001 C CNN
F 3 "~" H 2800 2900 50  0001 C CNN
	1    2800 2900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 619B7A77
P 2800 3050
F 0 "#PWR0101" H 2800 2800 50  0001 C CNN
F 1 "GND" H 2805 2877 50  0000 C CNN
F 2 "" H 2800 3050 50  0001 C CNN
F 3 "" H 2800 3050 50  0001 C CNN
	1    2800 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 2900 2950 3650
Wire Wire Line
	2950 3650 3500 3650
Wire Wire Line
	2800 2750 2800 1450
Wire Wire Line
	2800 1450 2900 1450
Connection ~ 2900 1450
Wire Wire Line
	5050 650  5050 2350
Connection ~ 4900 4350
$Comp
L OLEDBomb-rescue:ARDUINO_PRO_MINI-ARDUINO_PRO_MINI U4
U 1 1 60689EF5
P 4200 3350
F 0 "U4" H 4200 4717 50  0000 C CNN
F 1 "ARDUINO_PRO_MINI" H 4200 4626 50  0000 C CNN
F 2 "ARDUINO_PRO_MINI:MODULE_ARDUINO_PRO_MINI" H 4200 3350 50  0001 L BNN
F 3 "" H 4200 3350 50  0001 L BNN
F 4 "Manufacturer Recommendations" H 4200 3350 50  0001 L BNN "STANDARD"
F 5 "N/A" H 4200 3350 50  0001 L BNN "MAXIMUM_PACKAGE_HEIGHT"
F 6 "N/A" H 4200 3350 50  0001 L BNN "PARTREV"
F 7 "SparkFun Electronics" H 4200 3350 50  0001 L BNN "MANUFACTURER"
	1    4200 3350
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J3
U 1 1 61A0214F
P 2200 1150
F 0 "J3" H 2228 1126 50  0000 L CNN
F 1 "Battery" H 2228 1035 50  0000 L CNN
F 2 "TestPoint:TestPoint_2Pads_Pitch5.08mm_Drill1.3mm" H 2200 1150 50  0001 C CNN
F 3 "~" H 2200 1150 50  0001 C CNN
	1    2200 1150
	1    0    0    -1  
$EndComp
$Comp
L OLEDBomb-rescue:TP4056Board-ARDUINO_PRO_MINI U1
U 1 1 606C17EA
P 1400 1500
F 0 "U1" H 1375 2265 50  0000 C CNN
F 1 "TP4056Board" H 1375 2174 50  0000 C CNN
F 2 "ARDUINO_PRO_MINI:TP4056Board" H 1400 1500 50  0001 C CNN
F 3 "" H 1400 1500 50  0001 C CNN
	1    1400 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 1250 2000 1250
Wire Wire Line
	1950 1100 2000 1100
Wire Wire Line
	2000 1100 2000 1150
$EndSCHEMATC
