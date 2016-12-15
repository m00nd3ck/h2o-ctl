#include "i2c.h"

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

void i2c_status(void) {
  unsigned char status;
  status = TWSR & 0xF8;
  return status;
}
