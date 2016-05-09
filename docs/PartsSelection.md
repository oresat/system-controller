# Parts Selection for System Controller (work in progress) 
**Table of Contents**
* [Microcontroller]  
* [Voltage Regulation]  
* [Digital Components]  

Format note  

#### Format note  
Eagle Referance, Manufacturer, Manufacturer's Part Number  
Vendor  
Vendor Part No  
Datasheet  
Reasons  
Rad-hard Analogue  

#### U1 Atmel ATMega128:  
Vendor: Digi-Key 
Vendor Part No.: ATMEGA128-16AUR  
[Non-hardened Datasheet](http://www.atmel.com/images/doc2467.pdf)  
Reasons: Microcontroller has analogoues radiation hardened version meaning we can test at a low price. MCU is easily programmable.  
Rad-Hard Part No.: ATmegaS128	
[Rad-hard Datasheet](http://aerosupport.atmel.com/Atmel/doc41036.pdf)  

#### Possible radhard MOSFET:
Vendor: 
Vendor Part No.: ATMEGA128-16AUR  
<http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00295117.pdf>

#### Radhard LDO:
<http://www.intersil.com/content/dam/Intersil/documents/isl7/isl75052seh.pdf>
non-hardened part? <http://www.ti.com/lit/ds/symlink/tps7h1201-ht.pdf>
-same footprint, but inputs are different so not worth the trouble
Using the LNA LDO for the SysCon.

#### J1 CNC Tech 3220-10-0100-00:  
Part: JTAG Connector    
Vendor: Digi-Key  
Vendor Part No.: 1175-1627-ND   
[Datasheet](http://cnctech.us/pdfs/3220-XX-0100-00.pdf)  
Reasons: Generic JTAG connector used on practicum board. 

#### X1 Abaracon LLC ABM3-8.000MHZ-D2Y-T:  
Part:  8MHz +/- 20ppm Crystal    
Vendor: Digi-Key  
Vendor Part No.: 1535-10630-1-ND	
[Datasheet](http://www.abracon.com/Resonators/abm3.pdf)  
Reasons: Meets expected ppm and cost. 
  
#### U2 Texas Instruments LP5907MFX-3.0/NOPB: 
Part:  MCU LDO  
Vendor: Digi-Key  
Vendor Part No.: 296-40357-1-ND		
[Datasheet](http://www.ti.com/lit/ds/symlink/lp5907.pdf)  
Reasons: Quickly found replacement for Skyworks AAT3215 LDO. Has same package and pin-out.  

#### (#) Broadcom Limited ACPL-M61L-000E:
Part:OPTOISO 3.75KV PUSH PULL 5SO	
Vendor: Digi-Key  
Vendor Part#: 516-2169-5-ND		
[Datasheet](www.avagotech.com/docs/AV02-2150EN)  
Reasoning: Much less complex, has both a dual and single option 	
**_Alternatives_**
Part No: TLP2160  
[Datasheet](http://www.digikey.com/product-detail/en/toshiba-semiconductor-and-storage/TLP2160(TP,F)/TLP2160(TPF)CT-ND/5189796)  
Reasoning: Too complex  

#### C1 Elna America DSK-3R3H224U-HL:
Part: 220 mF SuperCap	
Vendor: Digi-Key  
Vendor Part#: 604-1020-1-ND		
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Elna%20America%20Inc/DS,DSK.pdf)
Reasoning: Already have footprint & symbol in Eagle. Known reliability from use on the GPS board. Should provide about 50~60 secs supply in the case of complete power down.

#### (#) Texas Instruments TPS25944LRVCR:
Part: IC Power Management eFuse 		
Vendor: Digi-Key  
Vendor Part#: 296-42152-1-ND		
[Datasheet](http://www.ti.com/lit/ds/symlink/tps25944a.pdf)		
Reasoning: Other potential eFUse ICs required external circuitry and compromised features. This one gave us all the features we need without the compromise and without the need for extra external parts.

#### Q13 Didoes Inc. DMN62D0U-13 
Part: N-channel MOSFET:		
Vendor: Digi-Key  
Vendor Part#: DMN62D0U-13DICT-ND	
[Datasheet](http://www.diodes.com/_files/datasheets/DMN62D0U.pdf)
Reasoning: Small footprint and cost

#### (#) Silicon Labs TS4100ITQ1633
part: 8:1 Mux	
Vendor: Digi-Key  
Vendor Part#: 336-3600-ND	
[Datasheet](http://www.silabs.com/Support%20Documents/TechnicalDocs/TS410x.pdf)		
Reasoning: Small footprint, Supply Voltage (0.8V - 5.25V) and supply current (675nA)

#### D1 Vishay SSC53L-E3/57T
part: Schottky Diode	
Vendor: Digi-Key  		
Vendor Part#: SSC53L-E3/57TGICT-ND	
[Datasheet](https://www.vishay.com/docs/88885/ssc53l.pdf)		
Reasoning: Similar Forward On Voltage to radhard eqivalent (0.45V)

#### ST 1N5819U:
part: Radhard Diode		
[Datasheet](http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00241480.pdf)

#### CF1 Harwin Inc. M50-3202045:     
Part: 40-Pinout Header     
Vendor: Digi-Key  
Vendor Part No.: 952-1381-5-ND  	  
[Datasheet](https://cdn.harwin.com/pdfs/60page104.pdf)  
Reasons: Design requirement for communication from the Cubesat and allows for communication between the LGR and the System Controller. 

#### D0A/0B Diodes Inc. DMG6601LVT-7:     
Part: MOSFET, N/P channel     
Vendor: Digi-Key  
Vendor Part No.: DMG6601LVT-7DICT-ND 	  
[Datasheet](http://www.diodes.com/_files/datasheets/DMG6601LVT.pdf)  
Reasons: Familiarity with reliability of chip as it was used on previous PSAS project. Bonus: Already had the Eagle package in the PSAS library.

### LEDs
**LED0, LED1, LED2, LED3, LED4, LED5, LED6, LED7, Wurth Electronics, Inc. 150060GS75000**:      
Part: Green LEDs    
Vendor: Digi-Key  
Vendor Part No.: 732-4971-1-ND 	
[Datasheet](http://katalog.we-online.de/led/datasheet/150060GS75000.pdf)  
Reasons: Green LEDs are used for debugging power. The green LEDs are placed at the front of the board for easy viewing and when on represent that the power line of interest is working. The green LEDs are on the VCB0 - VCB7 lines and are located between the output of the eFuse modules and the input of the 40 pin connector. They will be removed before actual launch.

**LED8, LED9, LED10, LED11, OSRAM Optp Semi. LA L296-Q2R2-1-Z**:      
Part: Amber LEDs    
Vendor: Digi-Key  
Vendor Part No.: 475-2712-1-ND  
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Osram%20PDFs/LS,LA,LO,LY_296.pdf)  
Reasons: Amber LEDs are used for error checks during debugging and are placed on the debugging lines for UART. They will also be removed before actual launch.

### Capacitors

**C2, C4, C6, C12, C14, C16, C20, C25, CFUSE3A, CLDO1 Samsung CL10B105KP8NNNC**:       
Part: 1µF ±10% 10V X7R Ceramic Capacitor SMD, MLCC 0603 
Vendor: Digi-Key  
Vendor Part No.: 1276-1946-1-ND  
[Datasheet](http://www.samsungsem.com/kr/support/product-search/mlcc/__icsFiles/afieldfile/2015/06/15/CL10B105KP8NNNC.pdf)  
Reasons: All capacitors are used as bypass caps. C2, C4, C6, C12, C14, C16, C20, and CFUSE3A are used on the eFuse ICs. C25 is found on the 8:1 Mux and CLD01 is on the LDO.

**C3, C5, C9, C11, C13, C15, C17, C19 Samsung CL10C222GA8NNNC**:       
Part: 2200pF ±2% 25V C0G, NP0 Ceramic Capacitor SMD, MLCC 0603
Vendor: Digi-Key  
Vendor Part No.: 1276-2239-1-ND		
[Datasheet](http://www.samsungsem.com/kr/support/product-search/mlcc/__icsFiles/afieldfile/2015/06/03/CL10C222GA8NNNC.pdf)  
Reasons: C3, C5, C9, C11, C13, C15, C17, C19 are used on the TPS25944LRVCR eFuse IC's to set the ramp rate of output voltage.

**C7, C8, Samsung CL10C090DB8NNNC**:       
Part: 9pF ±0.5pF 50V C0G, NP0 Ceramic Capacitor SMD, MLCC 0603 	
Vendor: Digi-Key  
Vendor Part No.: 1276-2143-1-ND		
[Datasheet](http://www.samsungsem.com/kr/support/product-search/mlcc/__icsFiles/afieldfile/2015/06/03/CL10C090DB8NNNC.pdf)  
Reasons: These caps compliment the 8MHz Crystal on the ATMega 128 microcontroller.

**CLDO3, Samsung CL10A225KQ8NNNC**:       
Part: 2.2µF ±10% 6.3V X5R Ceramic Capacitor SMD, MLCC 0603	
Vendor: Digi-Key  
Vendor Part No.: 1276-1183-1-ND		
[Datasheet](http://www.samsungsem.com/kr/support/product-search/mlcc/__icsFiles/afieldfile/2015/08/14/S_CL10A225KQ8NNNC.pdf)  
Reasons: Bypass Cap on the LDO. 

**CN1, Samsung CL10A226KQ8NRNE**:       
Part: 22µF ±10% 6.3V X5R Ceramic Capacitor SMD, MLCC 0603	
Vendor: Digi-Key  
Vendor Part No.: 1276-2867-2-ND		
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/CL10A226KQ8NRNE_Spec.pdf)  
Reasons: This capacitor is used on the Hardware Watchdog as part of an RC citcuit. 

**CLDO2, Kemet C0603C103J5RACTU**:       
Part: 10000pF ±5% 50V X7R Ceramic Capacitor SMD, MLCC 0603	
Vendor: Digi-Key  
Vendor Part No.: 399-1092-1-ND	
[Datasheet](http://www.kemet.com/docfinder?Partnumber=C0603C103J5RACTU)  
Reasons: Bypass Cap on the LDO.  

**C26, C27, C28, C30, C31, C32, C33, C34, Kemet C0603C103J5RACTU**:       
Part: 0.10µF ±5% 16V X7R Ceramic Capacitor SMD, MLCC 0603	
Vendor: Digi-Key  
Vendor Part No.: 399-1097-1-ND	
[Datasheet](http://www.kemet.com/Lists/ProductCatalog/Attachments/53/KEM_C1002_X7R_SMD.pdf)  
Reasons: Bypass C26, C27, C28, and C30 are used as bypass caps on the ATMega 128 microcontroller. C31, C32,C33, and C34 are bypass caps on the optoisolators.

#### Resistors

**RLDO1	Samsung	RC1608F103CS**:      
Part: RES SMD 10K OHM 1% 1/10W 0603
Vendor: Digi-Key  
Vendor Part No.: 1276-3485-1-ND 	
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: Used as a pull-up resistor on the LDO.    

**RIMON0, RIMON1, RIMON2, RIMON3, RIMON4, RIMON5, RIMON6, RIMON7, Samsung RC1608F3012CS**:      
Part: RES SMD 30K OHM 0.1% 1/10W 0603
Vendor: Digi-Key  
Vendor Part No.: 1276-4787-1-ND 	
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: These resistors are configured as current monitoring resistors for the eFuse circuitry. They allow the microcontroller to monitor the amount of current through the output of each eFuse IC.

**RNR, Samsung RC1608F474CS**:      
Part: RES SMD 470K OHM 1% 1/10W 0603
Vendor: Digi-Key  
Vendor Part No.: 1276-4902-1-ND  
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: This resistor is part of the RC time constant in the hardware watchdog.

**R4, R11, R47, R48, R49, R50, R51, R53, R54, RN1, RN2, RN3, RN4 Samsung RC0603FR-071KL**:      
Part: RES SMD 390 OHM 0.1% 1/16W 0603   
Vendor: Digi-Key  
Vendor Part No.: 1276-4610-1-ND 	
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: R4 is used as a pull-up resistor for the !RESET line on the ATMega 128. R11, R47, R48, R49, R50, R51, R53, and R54 are used as pull-up resistors on the Optoisolators. RN1, RN2, RN3, and RN4 are used as part of the hardware watchdog. 

**R2, R8, R14, R20, R28, R33, R38, R43 Yageo RC1608F472CS**:      
Part: RES SMD 4.7K OHM 1% 1/10W 0603 
Vendor: Digi-Key  
Vendor Part No.: 1276-3502-1-ND 	
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: These resistors are part of the external biasing of the eFuse section.

**R5, R10, R16, R25, R30, R35, R40, R45 Samsung RC1608F9312CS**:      
Part: RES SMD 93.1K OHM 1% 1/10W 0603 
Vendor: Digi-Key  
Vendor Part No.: 1276-4837-1-ND  
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: Used as under voltage lock out for the eFuse IC's. This is part of a voltage diveder network that sets the voltage at the EN/UVLO pin to 3V.

**R6, R12, R18, R22, R23, R24, R26, R31, R36, R41, R46, R61 Samsung RC1608F102CS**:      
Part: RES SMD 1K OHM 1% 1/10W 0603
Vendor: Digi-Key  
Vendor Part No.: 1276-3484-1-ND		
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons:  R22, R23, R24, and R61 are used as current limitting resistors on the Amber LEDs. R6, R12, R18, R26, R31, R36, R41, and R46 are used as current limitting resistors on the Green LEDs.

**R0/UVLO, R1, R1/UVLO, R2/UVLO, R3, R3/UVLO, R4/UVLO, R5/UVLO, R6/UVLO, R7, R7/UVLO, R9, R13, R15, R19, R21, R27, R29, R32, R34, R37, R39, R42, R44, RA0, RA1, RA2, RA3, RA4, RA5, RA6, RA7, RILIM0, RILIM1, RILIM2, RILIM3, RILIM4, RILIM5, RILIM6, RILIM7 Samsung RC1608F473CS**:      
Part: RES SMD 47K OHM 1% 1/10W 0603
Vendor: Digi-Key  
Vendor Part No.: 1276-4808-1-ND 	
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: R0/UVLO, R1/UVLO, R2/UVLO, R3/UVLO, R4/UVLO, R5/UVLO, R6/UVLO, and R7/UVLO are part of the volatage divider network that sets the UVLO voltage on the eFUse. Will continue...
