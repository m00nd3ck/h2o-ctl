#include <stdlib.h>
#include <stdint.h>
#include <avr/common.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#undef F_CPU
#define F_CPU 16000000
#include <util/delay.h>

#define PCF_ADDR 0x7E

void pcf_send(char pcf_adr,char pcf_val);
void disp_init_4bit();
void disp_cmd_4bit(char disp_cmd);
void disp_char(char character);