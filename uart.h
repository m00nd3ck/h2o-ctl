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

void UART_sendchar(char sendchar);
void UART_out(char *UART_out_text);
char UART_rec();