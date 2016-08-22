#include "adc.h"

/* ADCSRA */
#define ADEN (1 << 7)
#define ADFR (1 << 5)
#define ADPS2 (1 << 2)
#define ADPS1 (1 << 1)
#define ADPS0 (1 << 0)

/* ADMUX */
#define REFS1 (1 << 7)
#define REFS0 (1 << 6)
#define ADLAR (1 << 5)
#define MUX4 (1 << 4)
#define MUX3 (1 << 3)
#define MUX2 (1 << 2)
#define MUX1 (1 << 1)
#define MUX0 (1 << 0)

void adc_init(){
	/*
		voltage reference selection
		AVCC w/ external cap at AREF pin
         */
	ADMUX |= REFS0;
	ADMUX &= ~(REFS1 | ADLAR | MUX4 | MUX3 | MUX2 | MUX1 | MUX0);

  	/*
		set prescalar to 2
		this divides F_CPU by 2
		for ADC clock frequency
	*/
	ADCSRA &= ~(ADPS2 | ADPS1 | ADPS0);

	/*
		enable ADC in free run mode
         */
	ADCSRA |= (ADEN | ADFR);
}

uint16_t adc_read(){
	/* grab last two bits from ADCH register */
	uint8_t ADCHigh = ADCH & 0x3;

        /* grab contents of ADCL register */
	uint8_t ADCLow = ADCL;

	return ((ADCHigh << 8) | ADCLow);
}
