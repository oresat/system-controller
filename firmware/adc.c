#include "adc.h"

void adc_init(){
	/*
		voltage reference selection
		AVCC w/ external cap at AREF pin
         */
	ADMUX |= (1 << REFS0);
	ADMUX &= ~((1 << REFS1) |
		   (1 << ADLAR) |
                   (1 << MUX4) |
                   (1 << MUX3) |
                   (1 << MUX2) |
                   (1 << MUX1) |
                   (1 << MUX0));

  	/*
		set prescalar to 2
		this divides F_CPU by 2
		for ADC clock frequency
	*/
	ADCSRA &= ~((1 << ADPS2) |
                    (1 << ADPS1) |
                    (1 << ADPS0));

	/*
		enable ADC in free run mode
         */
	ADCSRA |= ((1 << ADEN) |
                   (1 << ADFR));
}

uint16_t adc_read(){
	/* grab last two bits from ADCH register */
	uint8_t ADCHigh = ADCH & 0x3;

        /* grab contents of ADCL register */
	uint8_t ADCLow = ADCL;

	return ((ADCHigh << 8) | ADCLow);
}
