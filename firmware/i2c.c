#include "i2c.h"

/* for some reason these aren't defined in the standard AVR stuff */
#ifndef TWBR3
#define TWBR3 3
#endif

#ifndef TWBR2
#define TWBR2 2
#endif

//void i2c_init(){
bool i2c_init(){
	/* set prescaler value to 1*/
    return (clearBit(&TWSR, TWPS1) &&
            clearBit(&TWSR, TWPS0) &&
            /* set SCL to 200kHz */            
            setBit(&TWBR, TWBR3) &&
            setBit(&TWBR, TWBR2) &&
           	/* enable TWI */
            setBit(&TWCR, TWEN));
}

static uint8_t i2c_status(){
	return TW_STATUS;
}

static void i2c_start(){
	/* send start condition */
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

        /*
		Wait for TWI interrupt flag to be set.
		Indicates start condition has been transmitted.
        */
	while(!(TWCR & (1 << TWINT)));
}

static void i2c_stop(){
	/* send stop condition */
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

static bool write_byte(uint8_t slave_addr, uint8_t data){
	if(slave_addr & 0x1){
        slave_addr &= ~(1 << 0);
    }

	/* send start condition */
	i2c_start();

	/* start condition not acknowledge */
	if(i2c_status() != TW_START &&
	   i2c_status() != TW_REP_START) return false;

	/* load slave */
	TWDR = slave_addr;

	/* clear interrupt flag */
	TWCR = (1 << TWINT) | (1 << TWEN);

	/* wait for interrupt to confirm transmission */
	while(!(TWCR & (1 << TWINT)));

	/* slave addr not acknowledged */
	if(i2c_status() != TW_MT_SLA_ACK) return false;

        /* load data */
	TWDR = data;

	/* wait for interrupt to confirm transmission */
	while(!(TWCR & (1 << TWINT)));

	/* data not acknowledged */
	if(i2c_status() != TW_MT_DATA_ACK) return false;

	return true;
}

static bool read_byte(uint8_t slave_addr, uint8_t * dest){
	if(!(slave_addr & 0x0)) slave_addr |= (1 << 0);

	/* send start condition */
	i2c_start();

	/* start condition not acknowledge */
	if(i2c_status() != TW_START &&
	   i2c_status() != TW_REP_START) return false;

	/* load slave */
	TWDR = slave_addr;

	/* clear interrupt flag */
	TWCR = (1 << TWINT) | (1 << TWEN);

	/* wait for interrupt to confirm transmission */
	while(!(TWCR & (1 << TWINT)));

	/* slave addr not acknowledged */
	if(i2c_status() != TW_MT_SLA_ACK) return false;

        TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);

	while(!(TWCR & (1 << TWINT)));

	*dest = TWDR;

	return true;
}

static bool read_byte_NACK(uint8_t slave_addr, uint8_t * dest){
	if(!(slave_addr & 0x0)) slave_addr |= (1 << 0);

	/* send start condition */
	i2c_start();

	/* start condition not acknowledge */
	if(i2c_status() != TW_START &&
	   i2c_status() != TW_REP_START) return false;

	/* load slave */
	TWDR = slave_addr;

	/* clear interrupt flag */
	TWCR = (1 << TWINT) | (1 << TWEN);

	/* wait for interrupt to confirm transmission */
	while(!(TWCR & (1 << TWINT)));

	/* slave addr not acknowledged */
	if(i2c_status() != TW_MT_SLA_ACK) return false;

    TWCR = (1 << TWINT) | (1 << TWEN);

	while(!(TWCR & (1 << TWINT)));

	*dest = TWDR;

	return true;
}

bool i2c_read(uint8_t slave_addr, uint8_t * dest, uint8_t len){
	uint8_t i;
	for(i = 0; i < len; i++){
		if(!read_byte(slave_addr + i, dest + i)) return false;

		/* last byte, wait for nack */
		if(i == (len - 1)){
			if(!read_byte_NACK(slave_addr + i, dest + i)) return false;
        }
	}
	i2c_stop();
	return true;
}

bool i2c_write(uint8_t slave_addr, uint8_t * data, uint8_t len){
	uint8_t i;
	for(i = 0; i < len; i++){
		if(!write_byte(slave_addr + i, *(data + i))) return false;
	}
	i2c_stop();
	return true;
}
