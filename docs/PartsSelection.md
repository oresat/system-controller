# Parts Selection  
**Table of Contents**
* [Microcontroller]  
* [Voltage Regulation]  
* [Digital Components]  

Format note  

EAGLE REF, MANF, MANF PART  
Vend  
Vend Part No  
Datasheet  
Reasons:  
Rad-hard:  

#### Microcontroller:  
Part No.: ATmega128  
Rad-Hard Part No.: ATmegaS128  
Manufacturer: Atmel  
Vendor:   
Vendor Part No.:  
Eagle Part Reference: U1  
[Non-hardened Datasheet](http://www.atmel.com/images/doc2467.pdf)  
[Rad-hard Datasheet](http://aerosupport.atmel.com/Atmel/doc41036S.pdf)  
Reasons: Microcontroller has analogoues radiation hardened version meaning we can test at a low price. MCU is easily programmable.  
  
#### Possible radhard MOSFET:
<http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00295117.pdf>

#### Radhard LDO:
<http://www.intersil.com/content/dam/Intersil/documents/isl7/isl75052seh.pdf>
non-hardened part? <http://www.ti.com/lit/ds/symlink/tps7h1201-ht.pdf>
-same footprint, but inputs are different so not worth the trouble
Using the LNA LDO for the SysCon.

#### Radhard Diode:
Single:http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00241480.pdf
non-hardened part: http://www.digikey.com/product-detail/en/microsemi-hi-rel-mil/JANTXV1N5806US/1086-2843-MIL/4349180

Dual:http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00277085.pdf

#### Optoisolator:
<http://www.digikey.com/product-detail/en/toshiba-semiconductor-and-storage/TLP2160(TP,F)/TLP2160(TPF)CT-ND/5189796>
-Too complex
<http://www.avagotech.com/docs/AV02-2150EN>
-Much less complex, has both a dual and single option

#### Super Cap:
<http://www.elna.co.jp/en/capacitor/double_layer/catalog/pdf/ds_e.pdf>
-Already have footprint & symbol in Eagle.
-Known reliability on the GPS board
-Should provide about 50~60secs supply in the case of complete power down

#### Inverter:
<https://www.fairchildsemi.com/datasheets/NC/NC7SZ05.pdf>
-Meets Vcc range
-simple design
-small package

#### Efuse/Switch:
<http://www.ti.com/lit/ds/slvsce9/slvsce9.pdf.pdf>
-eFuse switch used for undervoltage protection, and current limit protection
-Can be used to monitor current draw and fault
-looked at other possibilities but this one gave us all the features we need without extra external circuitry

#### N-channel MOSFET:
<http://www.irf.com/product-info/datasheets/data/irlml6344pbf.pdf>
-Simple MOSFET as enable switch for the eFuse
-Small footprint (SOT-23) 
-Cheap

#### 16:1 Multiplexer
<http://cache.nxp.com/documents/data_sheet/74HC_HCT4067.pdf?pspll=1>
-Small footprint - VQFN-24 (3.5 mm x 5.50 mm)
-Supply voltage range: 2 - 10 V

#### 8:1 Multiplexer
<http://www.silabs.com/Support%20Documents/TechnicalDocs/TS410x.pdf>
- Small footprint - TQFN-16 (3.00 mm x 3.00 mm)
-Supply voltage range: 0.8 - 5.25 V
-Supply current of 675nA


