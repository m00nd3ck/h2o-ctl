#include "main.h"

int main(void) {
  UBRR1H = UBRRH_VALUE;
  UBRR1L = UBRRL_VALUE;

  UCSR1B = (1 << RXEN1);
  UCSR1B = (1 << TXEN1);

  DDRD = (1 << DDD4);
  DDRD = (1 << DDD5);
  DDRC = (1 << DDD6);

  DDRB = (1 << DDB0);

  TWBR = 18;

  i2c_init();
  pcf_send(0x7E,0x00); //zero it out so we are in a known state

  
  while(1){
    i2c_start();
    i2c_send(0xD0);
    if (i2c_status() != 0x28) ;
    i2c_stop();
    
    
  }
}
