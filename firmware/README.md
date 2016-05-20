# System Controller Firmware

This folder contains the firmware for the system controller.
The system controller contains an [Atmega128](http://www.atmel.com/devices/ATMEGA128.aspx) which is a microcontroller developed by [Atmel](http://www.atmel.com/).
The microcontroller itself is composed of an [AVR based architecture](https://en.wikipedia.org/wiki/Atmel_AVR) which was developed by Atmel.
It is for this reason that the tool chain for the system controller and low gain radio are completely different.
Furthermore, the Atmega128 is not going to be used for actual flight/deployment in space. Instead, there is a [radiation-hardened version](http://www.atmel.com/devices/ATmegaS128.aspx) of it that we plan to use.
As far as programming is concerned, there is no difference between this version and the Atmega128.

## Dependencies

[avrdude](http://www.nongnu.org/avrdude/)

## Caveats

The Makefile assumes an Atmel AVR JTAGICE3 is being used with an Atmega128.

## Fuse bits

In order for the clock to function properly the currect fuse bits need to be set. This can be done in avrdude by including the following command line argument:

	-U lfuse:w:0xc0:m -U hfuse:w:0x89:m -U efuse:w:0xff:m

The CKOPT bit is set so that the crystal receives more power so that it can be detected reliably at 8MHz. If CKOPT is not set, the clock from the crystal wont be strong enough.

## Example usage

* To compile

    > make

* To complie and write to Atmega128

    > make load
