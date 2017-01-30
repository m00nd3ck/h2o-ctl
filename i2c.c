#include "i2c.h"

#define BL_STATE 1
void i2c_init(void) {
  TWSR = 0x00;
  TWCR = (1 < TWEN);
}

void i2c_start(void) {
  TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
  while ((TWCR & (1<<TWINT) ) == 0);
}

void i2c_stop(void) {
    TWCR = (1<<TWINT) | (1<<TWSTO) |( 1<<TWEN);
}

void i2c_send(unsigned char data) {
  TWDR = data;
  TWCR = (1<<TWINT) | (1<<TWEN);
  while ((TWCR & (1<<TWINT)) == 0);
}

char i2c_read() {
  
}

unsigned char i2c_status(void) {
  return (TWSR & 0xF8);
}

void pcf_send(char pcf_adr,char pcf_val) {
  i2c_start();
  i2c_send(pcf_adr);
  if (i2c_status() != 0x28) ;
  i2c_send(pcf_val);
  i2c_stop();
  _delay_us(100); //gotta give the chip some delay
}