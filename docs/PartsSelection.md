# Parts Selection for System Controller
**Table of Contents**	
* [Microcontroller](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#u1-atmel-atmega128)	
* [LDO](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#u2-texas-instruments-lp5907mfx-30nopb)	
* [Optical Isolator](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#u3-u4-u5-u6-broadcom-limited-acpl-m61l-000e)		
* [Power Management (eFuse)](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#u7-u8-u9-u10-u11-u12-u13-u14-texas-instruments-tps25944lrvcr) 	
* [8:1 Multiplexer](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#u15-silicon-labs-ts4100itq1633)		
* [SuperCap](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#c1-elna-america-dsk-3r3h224u-hl) 	
* [Schottky Diode](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#d1-d2-d3-vishay-ssc53l-e357t)		
* [8MHz Crystal](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#x1-abaracon-llc-abm3-8000mhz-d2y-t)		
* [MOSFETs](https://github.com/oresat/system-controller/blob/master/docs/PartsSelection.md#mosfets)		
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

#### U1 Atmel ATMega128  
Description: Microcontroller 8BIT 128KB FLASH 	
Vendor: Digi-Key 	
Vendor Part No.: ATMEGA128L-8AU 			
[Datasheet](http://www.atmel.com/images/doc2467.pdf)  
Reasons: The ATMega128 comes in both a radiation hardened and non-hardened version. This gives us the ability to fabricate and test the full board for functionality using the cheaper non-hardened version before purchasing the more expensive radiation tolerant part. An additional benefit is that the ATMega128 has a large community of users with access to open source code and documentation. This will help us bring the chip up quickly.
Rad-hard Analogue: ATmegaS128		
[Datasheet](http://aerosupport.atmel.com/Atmel/doc41036.pdf)  

#### U2 Texas Instruments LP5907MFX-3.0/NOPB 
Description:  MCU LDO  
Vendor: Digi-Key  
Vendor Part No.: 296-40357-1-ND		
[Datasheet](http://www.ti.com/lit/ds/symlink/lp5907.pdf)  
Reasons: This is a replacement for our original choice - the Skyworks AAT3215, which is not available through digikey. This one comes in the same package and it also has a functionally equivalent pin-out to the AAT3215. The input voltage range is 2.2V to 5.5 V and the drop out voltage is given at 120 mV.	
Rad-Hard Analogue: ISL75051SEH	
[Datasheet](http://www.intersil.com/content/dam/Intersil/documents/isl7/isl75051seh.pdf)	
Reasons: This chip is rated with a low drop out of 65mV at 1A (225mV at 3A). The IC operates over a voltage range of 2.2V to 6.0V and can provide output voltages between 0.8V and 5V. The output voltage is set using an external resistive voltage divider.

#### U3, U4, U5, U6 Broadcom Limited ACPL-M61L-000E
Description: Optoisolator 3.75KV PUSH PULL 	
Vendor: Digi-Key  
Vendor Part No.: 516-2169-5-ND		
[Datasheet](http://www.avagotech.com/docs/AV02-2150EN)  
Reasons: This IC is less complex than other comparable products. The chip can be powered from a 3.0V supply and features a low 1.6mA input current. The temperature range exceeds requirements on the high end (-40C to 105C). As a note, the output is inverted.		
Rad-hard Analogue: Avago HCPL5431		
[Datasheet](http://www.avagotech.com/docs/AV02-3838EN)

#### U7, U8, U9, U10, U11, U12, U13, U14 Texas Instruments TPS25944LRVCR
Description: IC Power Management eFuse 		
Vendor: Digi-Key  
Vendor Part No.: 296-42152-1-ND		
[Datasheet](http://www.ti.com/lit/ds/symlink/tps25944a.pdf)		
Reasons: This IC offered the most complete solution compared to the competition. The chip can be powered from a 3.0V supply (has an operating voltage range of 2.7V to 18V). It has a current limiting feature, which is set by an external resistor. It alows for current monitoring, undervoltage protection, overvoltage protection, and the slew rate is adjustable by use of an external capacitor.		
Rad-hard Analogue: Intersil ISL706		
[Datasheet](https://www.intersil.com/content/dam/Intersil/documents/isl7/isl705arh-05brh-05crh-05aeh-05beh-05ceh-06arh-06brh-06crh-06aeh-06beh-06ceh.pdf)

#### U15 Silicon Labs TS4100ITQ1633
Description: 8:1 Mux	/ Analog Switch
Vendor: Digi-Key  
Vendor Part No.: 336-3600-ND	
[Datasheet](http://www.silabs.com/Support%20Documents/TechnicalDocs/TS410x.pdf)		
Reasons: This chip could be considered generic as there were no specific reasons that it was chosen other than it can be powered from 3.0V and comes in a small 3 x 3 TQFN package.			
Rad-hard Analogue: ST M54HC4051		
[Datasheet](http://www2.st.com/content/ccc/resource/technical/document/datasheet/20/18/fe/5f/87/91/46/35/CD00270015.pdf/files/CD00270015.pdf/jcr:content/translations/en.CD00270015.pdf)

#### C1 Elna America DSK-3R3H224U-HL
Description: 220 mF SuperCap	
Vendor: Digi-Key  
Vendor Part No.: 604-1020-1-ND		
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Elna%20America%20Inc/DS,DSK.pdf)		
Reasons:  The same capacitor was used on a previous PSAS board and proved to be reliable. This capacitor should supply at least half a minute of charge if the power system fails.	 
Rad-hard Analogue: N/A

#### D1, D2, D3 Vishay SSC53L-E3/57T
Description: Schottky Diode	
Vendor: Digi-Key  		
Vendor Part No.: SSC53L-E3/57TGICT-ND	
[Datasheet](https://www.vishay.com/docs/88885/ssc53l.pdf)	
Reasons: This Diode was chosen because it has a similar turn-on voltage to the radiation hardened version.	
Rad-Hard Analogue: ST 1N5819U:		
[Datasheet](http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00241480.pdf)		
Reasons: Low Turn-on voltage. 

#### X1 Abaracon LLC ABM3-8.000MHZ-D2Y-T 
Description:  8MHz +/- 20ppm Crystal    
Vendor: Digi-Key  
Vendor Part No.: 1535-10630-1-ND	
[Datasheet](http://www.abracon.com/Resonators/abm3.pdf)  
Reasons: This is a good valued crystal with decent ppm count (+/-20ppm).	
Rad-hard Analogue: Swept Crystal		
[Datasheet](http://statek.com/products/pdf/SWCX1%20Swept%20Crystal%20Rev%20B.pdf)	
Reasons: The swept crystal is recommended for harsh environments. 


#### MOSFETs
**Q3 Didoes Inc. DMN62D0U-13**		
Description: MOSFET N-CH 60V 0.38A		
Vendor: Digi-Key  
Vendor Part No.: DMN62D0U-13DICT-ND		
[Datasheet](http://www.diodes.com/_files/datasheets/DMN62D0U.pdf)	
Reasons: This MOSFET was chosen based on the threshold voltage range of 0.5V to 1V. This allows the capacitor in the hardware watchdog circuitry more time to discharge from the 3V rail to where the FET turns off. Note: It has been dificult to find a radiation hardened transistor with a similar threshhold voltage range. This could be critical to reproducing the watchdog timing.				
Rad-Hard Option: Intentional Rectifier IRHLUB770Z4	
[Datasheet](http://www.irf.com/product-info/datasheets/data/irhlub770z4.pdf) 		
Reasons: Lowest Threshold voltage of any rad-hard FET viewed. This one is between 1V and 2V.

**Q9, Q11 On Semi. DMN62D0U-13** 
Description: MOSFET P-CH 20V 3.2A SOT23		
Vendor: Digi-Key  
Vendor Part No.: NTR4101PT1HOSCT-ND		
[Datasheet](http://www.onsemi.com/pub_link/Collateral/NTR4101P-D.PDF)	
Reasons: Generic P-channel MOSFET. 	
Rad-hard Analogue: International Rectifier IRHYB597Z30CM	
[Datasheet](http://www.irf.com/product-info/datasheets/data/irhyb597z30cm.pdf)		
Reasons: This transistor should be considered generic.

**Q1, Q2, Q4, Q5, Q6, Q7, Q8, Q10 Diodes Inc. DMG6601LVT-7**     
Description: MOSFET, N/P pair     
Vendor: Digi-Key  
Vendor Part No.: DMG6601LVT-7DICT-ND 	  
[Datasheet](http://www.diodes.com/_files/datasheets/DMG6601LVT.pdf)  
Reasons: This chip has been used in a previous PSAS design and has proved to be reliable.	
Rad-hard Analogue: International Rectifier IRHLUC7670Z4			
[Datasheet](http://www.irf.com/product-info/datasheets/data/irhluc7670z4.pdf)
Reasons: This chip should be considered generic.

#### Connectors
**J1 CNC Tech 3220-10-0100-00** 
Description: JTAG Connector    
Vendor: Digi-Key  
Vendor Part No.: 1175-1627-ND   
[Datasheet](http://cnctech.us/pdfs/3220-XX-0100-00.pdf)  
Reasons: This is a generic JTAG connector.	
Rad-hard Analogue: N/A	

**CF1, CF2 Harwin Inc. M50-3202045**     
Description: 40-Pinout Header     
Vendor: Digi-Key  
Vendor Part No.: 952-1381-5-ND  	  
[Datasheet](https://cdn.harwin.com/pdfs/60page104.pdf)  
Reasons: This is a design requirement for communication from the Cubesat and allows for a link between the LGR and System Controller.			
Rad-hard Analogue: N/A	

### LEDs
**LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8, LED13 Wurth Electronics, Inc. 150060GS75000**      
Description: Green LEDs    
Vendor: Digi-Key  
Vendor Part No.: 732-4971-1-ND 	
[Datasheet](http://katalog.we-online.de/led/datasheet/150060GS75000.pdf)  
Reasons: LED1 - LED8 are on the VCB0 - VCB7 lines and are functionally located between the output of the eFuse modules and the input of the 40 pin connector. LED13 is used to indicate 3.0V operation. They are placed at the front of the board for easy viewing and when on represent that the line of interest is working. These LEDs are for debugging only and will be removed before launch.			
Rad-hard Analogue: N/A	

**LED9, LED10, LED11, LED12 OSRAM Optp Semi. LA L296-Q2R2-1-Z**      
Description: Amber LEDs    
Vendor: Digi-Key  
Vendor Part No.: 475-2712-1-ND  
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Osram%20PDFs/LS,LA,LO,LY_296.pdf)  
Reasons: Amber LEDs are used for error checks during debugging and are placed on the debugging lines for UART. They will also be removed before actual launch.	
Rad-hard Analogue: N/A	

### Capacitors

**C1, C6, C7, C9, C14, C20, C22, C23, C25, C29 Samsung CL10B105KP8NNNC**       
Description: 1µF ±10% 10V X7R Ceramic Capacitor SMD, MLCC 0603 
Vendor: Digi-Key  
Vendor Part No.: 1276-1946-1-ND  
[Datasheet](http://www.samsungsem.com/kr/support/product-search/mlcc/__icsFiles/afieldfile/2015/06/15/CL10B105KP8NNNC.pdf)  
Reasons: These capacitors are used as bypass caps. C1, C7, C9, C14, C20, C22, C25, and C29 are used on the eFuse ICs. C23 is found on the 8:1 Mux and C6 is on the LDO.	
Rad-hard Analogue: N/A	

**C2, C8, C11, C16, C21, C24, C26, C30 Samsung CL10C222GA8NNNC**       
Description: 2200pF ±2% 25V C0G, NP0 Ceramic Capacitor SMD, MLCC 0603
Vendor: Digi-Key  
Vendor Part No.: 1276-2239-1-ND		
[Datasheet](http://www.samsungsem.com/kr/support/product-search/mlcc/__icsFiles/afieldfile/2015/06/03/CL10C222GA8NNNC.pdf)  
Reasons: C2, C8, C11, C16, C21, C24, C26, and C30 are used on the TPS25944LRVCR eFuse IC's to set the ramp rate of output voltage.	
Rad-hard Analogue: N/A	

**C15, C17 Samsung CL10C090DB8NNNC**       
Description: 9pF ±0.5pF 50V C0G, NP0 Ceramic Capacitor SMD, MLCC 0603	
Vendor: Digi-Key  
Vendor Part No.: 1276-2143-1-ND		
[Datasheet](http://www.samsungsem.com/kr/support/product-search/mlcc/__icsFiles/afieldfile/2015/06/03/CL10C090DB8NNNC.pdf)  
Reasons: These caps compliment the 8MHz Crystal on the ATMega128 microcontroller.	
Rad-hard Analogue: N/A	

**C5 Samsung CL10A225KQ8NNNC**       
Description: 2.2µF ±10% 6.3V X5R Ceramic Capacitor SMD, MLCC 0603	
Vendor: Digi-Key  
Vendor Part No.: 1276-1183-1-ND		
[Datasheet](http://www.samsungsem.com/kr/support/product-search/mlcc/__icsFiles/afieldfile/2015/08/14/S_CL10A225KQ8NNNC.pdf)  
Reasons: C5 is used as a bypass capacitor on the LDO. 	
Rad-hard Analogue: N/A	

**C10 Samsung CL10A226KQ8NRNE**       
Description: 22µF ±10% 6.3V X5R Ceramic Capacitor SMD, MLCC 0603	
Vendor: Digi-Key  
Vendor Part No.: 1276-2867-2-ND		
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/CL10A226KQ8NRNE_Spec.pdf)  
Reasons: This capacitor is used on the Hardware Watchdog as part of the RC timing circuit.	 
Rad-hard Analogue: N/A	

**C4 Kemet C0603C103J5RACTU**       
Description: 10000pF ±5% 50V X7R Ceramic Capacitor SMD, MLCC 0603	
Vendor: Digi-Key  
Vendor Part No.: 399-1092-1-ND	
[Datasheet](http://www.kemet.com/docfinder?Partnumber=C0603C103J5RACTU)  
Reasons: C4 is used as a bypass Cap on the AAT3215 LDO.	It is not used on the current LDO as that pin is a no connect.	
Rad-hard Analogue: N/A
	 

**C12, C13, C18, C19, C27, C28, C31, C32 Kemet C0603C103J5RACTU**       
Description: 0.10µF ±5% 16V X7R Ceramic Capacitor SMD, MLCC 0603	
Vendor: Digi-Key  
Vendor Part No.: 399-1097-1-ND	
[Datasheet](http://www.kemet.com/Lists/ProductCatalog/Attachments/53/KEM_C1002_X7R_SMD.pdf)  
Reasons: C12, C13, C18, and C19 are used as bypass caps on the ATMega128 microcontroller. C27, C28, C31, and C32 are used as bypass caps on the optoisolators.	
Rad-hard Analogue: N/A	
#### Resistors

**R7	Samsung	RC1608F103CS**      
Description: RES SMD 10K OHM 1% 1/10W 0603				
Vendor: Digi-Key				  
Vendor Part No.: 1276-3485-1-N				 	
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: This 10k resistor is used as a pull-up resistor on the LDO.		
Rad-hard Analogue: N/A	    

**RIMON1, RIMON2, RIMON3, RIMON4, RIMON5, RIMON6, RIMON7, RIMON8 Samsung RC1608F3012CS**      
Description: RES SMD 30.1K OHM 1% 1/10W 0603				
Vendor: Digi-Key			  
Vendor Part No.: 1276-4787-1-N				 	
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: These resistors are configured as current monitoring resistors for the eFuse circuitry. They allow the microcontroller to monitor the amount of current through the output of each eFuse IC.	
Rad-hard Analogue: N/A	

**R18 Samsung RC1608F474CS**      
Description: RES SMD 470K OHM 1% 1/10W 0603				
Vendor: Digi-Key			  
Vendor Part No.: 1276-4902-1-ND 				 
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: This resistor is part of the RC timing circuit in the hardware watchdog. It compliments capacitor C10 for this purpose.
Rad-hard Analogue: N/A	

**R14, R15, R16, R19, R25, R54, R60, R61, R70, R72, R74  Samsung RC0603FR-071KL**      
Description: RES SMD 390 OHM 0.1% 1/16W 060			   
Vendor: Digi-Key				  
Vendor Part No.: 1276-4610-1-N				 	
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: R25 is used as a pull-up resistor for the !RESET line on the ATMega128. R54, R61, R70, and R74 are used as pull-up resistors on the Optoisolators. R60 and R72 are on the output lines of the optoisolators and act as pull down resistors when the output is low. RN14, RN15, RN16, and RN19 are used as part of the hardware watchdog voltage divide network. 	
Rad-hard Analogue: N/A	

**R4, R11, R22, R29, R43, R49, R57, R67 Yageo RC1608F472CS**     
Description: RES SMD 4.7K OHM 1% 1/10W 060				 
Vendor: Digi-Key				  
Vendor Part No.: 1276-3502-1-N				 	
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: These resistors are part of the external biasing of the eFuse section P/N MOSFET network.	
Rad-hard Analogue: N/A	

**R2, R9, R20, R27, R41, R47, R55, R65 Samsung RC1608F9312CS**      
Description: RES SMD 93.1K OHM 1% 1/10W 060			 
Vendor: Digi-Key				  
Vendor Part No.: 1276-4837-1-ND 				 
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: Used as under voltage lock out for the eFuse IC's. This is part of a voltage divider network that sets the voltage at the EN/UVLO pin to 3V.	
Rad-hard Analogue: N/A	

**R3, R10, R21, R28, R42, R48, R52, R56, R63, R66, R71, R75, R76 Samsung RC1608F102CS**      
Description: RES SMD 1K OHM 1% 1/10W 0603		
Vendor: Digi-Key		 
Vendor Part No.: 1276-3484-1-ND				
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons:  R52, R63, R71, and R75 are used as current limiting resistors on the Amber LEDs. R3, R10, R21, R28, R42, R48, R56, R66, and R76 are used as current limiting resistors on the Green LEDs.	
Rad-hard Analogue: N/A	

**R1, R5, R6, R8, R12, R13, R17, R23, R24, R26, R30, R31, R32, R33, R34, R35, R36, R37, R38, R39, R40, R44, R45, R46, R50, R51, R53, R58, R59, R62, R64, R68, R69, R73, RILIM1, RILIM2, RILIM3, RILIM4, RILIM5, RILIM6, RILIM7, RILIM8 Samsung RC1608F473CS**      
Description: RES SMD 47K OHM 1% 1/10W 0603		
Vendor: Digi-Key		 
Vendor Part No.: 1276-4808-1-ND 			
[Datasheet](http://media.digikey.com/pdf/Data%20Sheets/Samsung%20PDFs/RC_Series_ds.pdf)  
Reasons: R5, R12, R23, R30, R44, R50, R58, and R68 are part of the voltage divider network that sets the UVLO voltage on the eFues. R1, R5, R8, R12, R17, R23, R26, R30, R40, R44, R46, R50, R53, and R64 are used as part of the bias on the eFuse P/N MOSFET network. R32, R33, R34, R35, R36, R37, R38, R39 are used as pull up resistors on the VCB0-VCB7_FLT lines. RILIM0, RILIM1, RILIM2, RILIM3, RILIM4, RILIM5, RILIM6, RILIM7 are used to limit the current through the eFuse to 1.9A.	
Rad-hard Analogue: N/A	
