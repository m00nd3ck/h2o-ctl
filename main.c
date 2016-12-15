#include <stdlib.h>
#include <stdint.h>
#include <avr/common.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#undef F_CPU
#define F_CPU 16000000
#define BAUD 9600

#include <util/delay.h>
#include <util/setbaud.h>

char data = 0;
char selftest_loop = 0;

void UART_sendchar(char sendchar) {
  while (!(UCSR1A & (1 << UDRE1)));
  UDR1 = sendchar;
}

void UART_out(char *UART_out_text) {
  while(*UART_out_text != 0){
    UART_sendchar(*UART_out_text);
    UART_out_text++;
  }
}

char UART_rec() {
  return UDR1;
}

void msgout(char *msgtext,int msglvl) {
  switch (msglvl) {
    case 1:
      UART_out("[MSG] ");
      break;
    case 2:
      UART_out("[DBG] ");
      break;
    case 3:
      UART_out("[ERR] ");
      break;
    case 4:
      UART_out("[CRITICAL] ");
      break;
  }
  UART_out(msgtext);
  UART_out("\n\r");
}

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


  while (1) {
    i2c_start();
    i2c_send(0x7E);
    if (i2c_status() != 0x28) ;
    i2c_send(0b10101010);
    i2c_stop();

  }
}
