#include <stdint.h>
#include <avr/common.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "lcd_lib_4bit/lcd_drv.hpp"

#define F_CPU 16000000
#define BAUD 9600

#include <util/delay.h>
#include <util/setbaud.h>

void UART_sendchar(char sendchar) {
  _delay_ms(1);
  UDR1 = sendchar;
}

void UART_out(char *UART_out_text) {
  while(*UART_out_text != 0){
    UART_sendchar(*UART_out_text);
    UART_out_text++;
  }
}

int main(void) {
  //_hd44780_drv::init_lcd();
  UBRR1H = UBRRH_VALUE;
  UBRR1L = UBRRL_VALUE;

  UCSR1B = (1 << RXEN1);
  UCSR1B = (1 << TXEN1);



  //asm("hlt");
}
