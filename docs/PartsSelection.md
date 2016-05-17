# Parts Selection for System Controller (work in progress) 
**Table of Contents**	
* [Microcontroller](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#u1-atmel-atmega128)	
* [LDO](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#u2-texas-instruments-lp5907mfx-30nopb)	
* [Optical Isolator](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#u3-u4-u5-u6-broadcom-limited-acpl-m61l-000e)		
* [Power Management (eFuse)](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#u7-u8-u9-u10-u11-u12-u13-u14-texas-instruments-tps25944lrvcr) 	
* [8:1 Multiplexer](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#u15-silicon-labs-ts4100itq1633)		
* [SuperCap](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#c1-elna-america-dsk-3r3h224u-hl) 	
* [Schottky Diode](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#d1-vishay-ssc53l-e357t)		
* [8MHz Crystal](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#x1-abaracon-llc-abm3-8000mhz-d2y-t)		
* [Transistors](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#mosfets)		
* [Connectors](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#connectors)				
* [LEDs](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#leds)	
* [Capacitors](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#capacitors)	
* [Resistors](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#resistors)



Format note  

#### Format note  
Eagle Reference, Manufacturer, Manufacturer's Part Number  
Vendor  
Vendor Part No  
Datasheet  
Reasons  
Rad-hard Analogue 

#### U1 Atmel ATMega128:  
Part: Microcontroller 8BIT 128KB FLASH 	
Vendor: Digi-Key 	
Vendor Part No.: ATMEGA128L-8AU 			
[Datasheet](http://www.atmel.com/images/doc2467.pdf)  
Reasons: The ATMega 128 comes in both a radiation hardened and non-hardened version. This gives us the ability to fabricate and test the full board for functionality using the cheaper non-hardened version before purchasing the more expensive radiation tolerant part. An additional benefit is that the ATMega128 has a large community of users with access to open source code and documentaion. This will help us bring the chip up quickly.
Rad-hard Analogue: ATmegaS128		
[Datasheet](http://aerosupport.atmel.com/Atmel/doc41036.pdf)  

#### U2 Texas Instruments LP5907MFX-3.0/NOPB: 
Part:  MCU LDO  
Vendor: Digi-Key  
Vendor Part No.: 296-40357-1-ND		
[Datasheet](http://www.ti.com/lit/ds/symlink/lp5907.pdf)  
Reasons: This is a replacement for our original choice - the Skyworks AAT3215, which is not available through digikey. This one comes in the same package style and it also has a functionally equivalent pin-out to the AAT3215. The input voltage range is 2.2V to 5.5 V and the drop out voltage is a low 120 mV.	
Rad-Hard Analogue: ISL75052SEH	
[Datasheet](http://www.intersil.com/content/dam/Intersil/documents/isl7/isl75052seh.pdf)	
Reasons: This IC shares the same footprint as the LP5907MFX. Unfortunately, the pin-out is different so this chip does not offer a direct plug-and-play option for the rad-hard upgrade.

#### U3, U4, U5, U6 Broadcom Limited ACPL-M61L-000E:
Part: Optoisolator 3.75KV PUSH PULL 	
Vendor: Digi-Key  
Vendor Part No.: 516-2169-5-ND		
[Datasheet](http://www.avagotech.com/docs/AV02-2150EN)  
Reasons: This IC is less complex than other comparable products. The chip can be powered from a 3.0V supply and features a low 1.6mA input current. The temperature range exceeds requirements on the high end (-40C to 105C). As a note, the output is inverted.		
Rad-hard Analogue: Avago HCPL5431		
[Datasheet](http://www.avagotech.com/docs/AV02-3838EN)

#### U7, U8, U9, U10, U11, U12, U13, U14 Texas Instruments TPS25944LRVCR:
Part: IC Power Management eFuse 		
Vendor: Digi-Key  
Vendor Part No.: 296-42152-1-ND		
[Datasheet](http://www.ti.com/lit/ds/symlink/tps25944a.pdf)		
Reasons: This IC offered the most complete solution compared to the competition. The chip can be powered from a 3.0V supply (has an operating voltage range of 2.7V to 18V). It has a current limiting feature, which is set by an external resistor. It alows for current monitoring, undervoltage protection, overvoltage protection, and the slew rate is adjustable through an external capacitor.		
Rad-hard Analogue: Intersil ISL706		
[Datasheet](http://www.intersil.com/content/dam/Intersil/documents/isl7/isl705aeh-05beh-05ceh-06aeh-06beh-06ceh.pdf)

#### U15 Silicon Labs TS4100ITQ1633
Part: 8:1 Mux	/ Analog Switch
Vendor: Digi-Key  
Vendor Part No.: 336-3600-ND	
[Datasheet](http://www.silabs.com/Support%20Documents/TechnicalDocs/TS410x.pdf)		
Reasons: This chip could be considered generic as there were no specific reasons that it was chosen other than it can be powered from 3.0V and comes in a small 3 x 3 TQFN package.			
Rad-hard Analogue: ST M54HC4051		
[Datasheet](http://www2.st.com/content/ccc/resource/technical/document/datasheet/20/18/fe/5f/87/91/46/35/CD00270015.pdf/files/CD00270015.pdf/jcr:content/translations/en.CD00270015.pdf)

#### C1 Elna America DSK-3R3H224U-HL:
Part: 220 mF SuperCap	
Vendor: Digi-Key  
Vendor Part No.: 604-1020-1-ND		
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Elna%20America%20Inc/DS,DSK.pdf)		
Reasons:  The same capacitor was used on a previous PSAS project and proved to be reliable. This capacitor should supply about half a minute of charge if the power system fails.	 
Rad-hard Analogue: N/A

#### D1 Vishay SSC53L-E3/57T
Part: Schottky Diode	
Vendor: Digi-Key  		
Vendor Part No.: SSC53L-E3/57TGICT-ND	
[Datasheet](https://www.vishay.com/docs/88885/ssc53l.pdf)	
Reasons: This Diode was chosen because it has a similar turn-on voltage to the radiation hardened version.	
Rad-Hard Analogue: ST 1N5819U:		
[Datasheet](http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00241480.pdf)		
Reasons: Low Turn-on voltage. 

#### X1 Abaracon LLC ABM3-8.000MHZ-D2Y-T:  
Part:  8MHz +/- 20ppm Crystal    
Vendor: Digi-Key  
Vendor Part No.: 1535-10630-1-ND	
[Datasheet](http://www.abracon.com/Resonators/abm3.pdf)  
Reasons: This is a good valued crystal with decent ppm count.	
Rad-hard Analogue: Swept Crystal		
[Datasheet](http://statek.com/products/pdf/SWCX1%20Swept%20Crystal%20Rev%20B.pdf)	
Reasons: The swept crystal is recommended for harsh environments. 


#### MOSFETs
**Q13 Didoes Inc. DMN62D0U-13:**		
Part: OSFET N-CH 60V 0.38A:		
Vendor: Digi-Key  
Vendor Part No.: DMN62D0U-13DICT-ND		
[Datasheet](http://www.diodes.com/_files/datasheets/DMN62D0U.pdf)	
Reasons: This MOSFET was chosen based on the threshold voltage range of 0.5V to 1V. This allows the capacitor in the hardware watchdog more time to discharge from the 3V rail to where the FET turns off. Note: It has been dificult to find a radiation hardened version of this transistor. 				
Rad-Hard Option: Intentional Rectifier IRHLUB770Z4	
[Datasheet](http://www.irf.com/product-info/datasheets/data/irhlub770z4.pdf) 		
Reasons: Lowest Threshold voltage of any rad-hard FET viewed. This one is between 1V and 2V.

**Q10, Q12 On Semi. DMN62D0U-13:** 
Part: MOSFET P-CH 20V 3.2A SOT23:		
Vendor: Digi-Key  
Vendor Part No.: NTR4101PT1HOSCT-ND		
[Datasheet](http://www.onsemi.com/pub_link/Collateral/NTR4101P-D.PDF)	
Reasons: Generic P-channel MOSFET. 	
Rad-hard Analogue: International Rectifier IRHYB597Z30CM	
[Datasheet](http://www.irf.com/product-info/datasheets/data/irhyb597z30cm.pdf)		
Reasons: There are not a lot of rad-hard p-channel mosfets to choose from. This one had some similar characteristics to the non-hardened version. Otherwise it could be considered generic.

**Q0A/B, Q1A/B, Q2A/B, Q3A/B, Q4A/B, Q5A/B, Q6A/B, Q7A/B Diodes Inc. DMG6601LVT-7**:     
Part: MOSFET, N/P pair     
Vendor: Digi-Key  
Vendor Part No.: DMG6601LVT-7DICT-ND 	  
[Datasheet](http://www.diodes.com/_files/datasheets/DMG6601LVT.pdf)  
Reasons: This chip has been used in a previous PSAS design and has proved to be reliable.	
Rad-hard Analogue: International Rectifier IRHLUC7670Z4			
[Datasheet](http://www.irf.com/product-info/datasheets/data/irhluc7670z4.pdf)
Reasons: Again, there are not a lot of rad-hard mosfets to choose from. This chip could be considered generic.

#### Connectors
**J1 CNC Tech 3220-10-0100-00:** 
Part: JTAG Connector    
Vendor: Digi-Key  
Vendor Part No.: 1175-1627-ND   
[Datasheet](http://cnctech.us/pdfs/3220-XX-0100-00.pdf)  
Reasons: This is a generic JTAG connector.	
Rad-hard Analogue: N/A	

**CF1 Harwin Inc. M50-3202045:**     
Part: 40-Pinout Header     
Vendor: Digi-Key  
Vendor Part No.: 952-1381-5-ND  	  
[Datasheet](https://cdn.harwin.com/pdfs/60page104.pdf)  
Reasons: This is a design requirement for communication from the Cubesat and allows for a link between the LGR and System Controller.			
Rad-hard Analogue: N/A	

### LEDs
**LED0, LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED 13 Wurth Electronics, Inc. 150060GS75000**:      
Part: Green LEDs    
Vendor: Digi-Key  
Vendor Part No.: 732-4971-1-ND 	
[Datasheet](http://katalog.we-online.de/led/datasheet/150060GS75000.pdf)  
Reasons: LED0 - LED7 are on the VCB0 - VCB7 lines and are functionally located between the output of the eFuse modules and the input of the 40 pin connector. LED13 is functionally located at on the output of the 3V LDO. They are placed at the front of the board for easy viewing and when on represent that the line of interest is working. These LEDs are for debugging only and will be removed before launch.			
Rad-hard Analogue: N/A	

**LED8, LED9, LED10, LED11, OSRAM Optp Semi. LA L296-Q2R2-1-Z**:      
Part: Amber LEDs    
Vendor: Digi-Key  
Vendor Part No.: 475-2712-1-ND  
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Osram%20PDFs/LS,LA,LO,LY_296.pdf)  
Reasons: Amber LEDs are used for error checks during debugging and are placed on the debugging lines for UART. They will also be removed before actual launch.	
Rad-hard Analogue: N/A	

### Capacitors

**C2, C4, C6, C12, C14, C16, C20, C21, C22, C25 Samsung CL10B105KP8NNNC**:       
Part: 1µF ±10% 10V X7R Ceramic Capacitor SMD, MLCC 0603 
Vendor: Digi-Key  
Vendor Part No.: 1276-1946-1-ND  
[Datasheet](http://www.samsungsem.com/kr/support/product-search/mlcc/__icsFiles/afieldfile/2015/06/15/CL10B105KP8NNNC.pdf)  
Reasons: All capacitors are used as bypass caps. C2, C4, C6, C12, C14, C16, C20, and CFUSE3A are used on the eFuse ICs. C25 is found on the 8:1 Mux and CLD01 is on the LDO.	
Rad-hard Analogue: N/A	

**C3, C5, C9, C11, C13, C15, C17, C19 Samsung CL10C222GA8NNNC**:       
Part: 2200pF ±2% 25V C0G, NP0 Ceramic Capacitor SMD, MLCC 0603
Vendor: Digi-Key  
Vendor Part No.: 1276-2239-1-ND		
[Datasheet](http://www.samsungsem.com/kr/support/product-search/mlcc/__icsFiles/afieldfile/2015/06/03/CL10C222GA8NNNC.pdf)  
Reasons: C3, C5, C9, C11, C13, C15, C17, C19 are used on the TPS25944LRVCR eFuse IC's to set the ramp rate of output voltage.	
Rad-hard Analogue: N/A	

**C7, C8, Samsung CL10C090DB8NNNC**:       
Part: 9pF ±0.5pF 50V C0G, NP0 Ceramic Capacitor SMD, MLCC 0603	
Vendor: Digi-Key  
Vendor Part No.: 1276-2143-1-ND		
[Datasheet](http://www.samsungsem.com/kr/support/product-search/mlcc/__icsFiles/afieldfile/2015/06/03/CL10C090DB8NNNC.pdf)  
Reasons: These caps compliment the 8MHz Crystal on the ATMega 128 microcontroller.	
Rad-hard Analogue: N/A	

**C29, Samsung CL10A225KQ8NNNC**:       
Part: 2.2µF ±10% 6.3V X5R Ceramic Capacitor SMD, MLCC 0603	
Vendor: Digi-Key  
Vendor Part No.: 1276-1183-1-ND		
[Datasheet](http://www.samsungsem.com/kr/support/product-search/mlcc/__icsFiles/afieldfile/2015/08/14/S_CL10A225KQ8NNNC.pdf)  
Reasons: Bypass Cap on the LDO. 	
Rad-hard Analogue: N/A	
I
**C24, Samsung CL10A226KQ8NRNE**:       
Part: 22µF ±10% 6.3V X5R Ceramic Capacitor SMD, MLCC 0603	
Vendor: Digi-Key  
Vendor Part No.: 1276-2867-2-ND		
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/CL10A226KQ8NRNE_Spec.pdf)  
Reasons: This capacitor is used on the Hardware Watchdog as part of the RC timer.	 
Rad-hard Analogue: N/A	

**C23, Kemet C0603C103J5RACTU**:       
Part: 10000pF ±5% 50V X7R Ceramic Capacitor SMD, MLCC 0603	
Vendor: Digi-Key  
Vendor Part No.: 399-1092-1-ND	
[Datasheet](http://www.kemet.com/docfinder?Partnumber=C0603C103J5RACTU)  
Reasons: Bypass Cap on the LDO. 		
Rad-hard Analogue: N/A
	 

**C26, C27, C28, C30, C31, C32, C33, C34, Kemet C0603C103J5RACTU**:       
Part: 0.10µF ±5% 16V X7R Ceramic Capacitor SMD, MLCC 0603	
Vendor: Digi-Key  
Vendor Part No.: 399-1097-1-ND	
[Datasheet](http://www.kemet.com/Lists/ProductCatalog/Attachments/53/KEM_C1002_X7R_SMD.pdf)  
Reasons: Bypass C26, C27, C28, and C30 are used as bypass caps on the ATMega 128 microcontroller. C31, C32,C33, and C34 are bypass caps on the optoisolators.	
Rad-hard Analogue: N/A	
#### Resistors

**R60	Samsung	RC1608F103CS**:      
Part: RES SMD 10K OHM 1% 1/10W 0603				
Vendor: Digi-Key				  
Vendor Part No.: 1276-3485-1-N				 	
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: Used as a pull-up resistor on the LDO.		
Rad-hard Analogue: N/A	    

**RIMON0, RIMON1, RIMON2, RIMON3, RIMON4, RIMON5, RIMON6, RIMON7, Samsung RC1608F3012CS**:      
Part: RES SMD 30K OHM 0.1% 1/10W 0603				
Vendor: Digi-Key			  
Vendor Part No.: 1276-4787-1-N				 	
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: These resistors are configured as current monitoring resistors for the eFuse circuitry. They allow the microcontroller to monitor the amount of current through the output of each eFuse IC.	
Rad-hard Analogue: N/A	

**R62, Samsung RC1608F474CS**:      
Part: RES SMD 470K OHM 1% 1/10W 0603				
Vendor: Digi-Key			  
Vendor Part No.: 1276-4902-1-ND 				 
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: This resistor is part of the RC circuit in the hardware watchdog and it compliments C24 to set the time constant for the charge rate and discharge rate of the capacitor.	
Rad-hard Analogue: N/A	

**R4, R11, R47, R48, R49, R50, R51, R53, R54, R63, R64, R65, R66 Samsung RC0603FR-071KL**:      
Part: RES SMD 390 OHM 0.1% 1/16W 060			   
Vendor: Digi-Key				  
Vendor Part No.: 1276-4610-1-N				 	
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: R4 is used as a pull-up resistor for the !RESET line on the ATMega 128. R11, R47, R48, R49, R50, R51, R53, and R54 are used as pull-up resistors on the Optoisolators. RN1, RN2, RN3, and RN4 are used as part of the hardware watchdog voltage divide network. 	
Rad-hard Analogue: N/A	

**R2, R8, R14, R20, R28, R33, R38, R43 Yageo RC1608F472CS**:      
Part: RES SMD 4.7K OHM 1% 1/10W 060				 
Vendor: Digi-Key				  
Vendor Part No.: 1276-3502-1-N				 	
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: These resistors are part of the external biasing of the eFuse section P/N MOSFET network.	
Rad-hard Analogue: N/A	

**R5, R10, R16, R25, R30, R35, R40, R45 Samsung RC1608F9312CS**:      
Part: RES SMD 93.1K OHM 1% 1/10W 060			 
Vendor: Digi-Key				  
Vendor Part No.: 1276-4837-1-ND 				 
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: Used as under voltage lock out for the eFuse IC's. This is part of a voltage divider network that sets the voltage at the EN/UVLO pin to 3V.	
Rad-hard Analogue: N/A	

**R6, R12, R18, R22, R23, R24, R26, R31, R36, R41, R46, R61 Samsung RC1608F102CS**:      
Part: RES SMD 1K OHM 1% 1/10W 0603		
Vendor: Digi-Key		 
Vendor Part No.: 1276-3484-1-ND				
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons:  R22, R23, R24, and R61 are used as current limiting resistors on the Amber LEDs. R6, R12, R18, R26, R31, R36, R41, and R46 are used as current limiting resistors on the Green LEDs.	
Rad-hard Analogue: N/A	

**R0/UVLO, R1, R1/UVLO, R2/UVLO, R3, R3/UVLO, R4/UVLO, R5/UVLO, R6/UVLO, R7, R7/UVLO, R9, R13, R15, R19, R21, R27, R29, R32, R34, R37, R39, R42, R44, RA0, RA1, RA2, RA3, RA4, RA5, RA6, RA7, RILIM0, RILIM1, RILIM2, RILIM3, RILIM4, RILIM5, RILIM6, RILIM7 Samsung RC1608F473CS**:      
Part: RES SMD 47K OHM 1% 1/10W 0603		
Vendor: Digi-Key		 
Vendor Part No.: 1276-4808-1-ND 			
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: R0/UVLO, R1/UVLO, R2/UVLO, R3/UVLO, R4/UVLO, R5/UVLO, R6/UVLO, and R7/UVLO are part of the voltage divider network that sets the UVLO voltage on the eFues. R1, R3, R7, R9, R13, R15, R19, R21, R27, R29, R32, R34, R37, R39, R42, R44 are used as part of the bias on the eFuse P/N MOSFET network. RA0, RA1, RA2, RA3, RA4, RA5, RA6, RA7 are used as pull up resistors on the VCBX_FLT lines. RILIM0, RILIM1, RILIM2, RILIM3, RILIM4, RILIM5, RILIM6, RILIM7 are used to limit the current through the eFuse to 1.9A.	
Rad-hard Analogue: N/A	
