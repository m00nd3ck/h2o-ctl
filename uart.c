#include "uart.h"

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