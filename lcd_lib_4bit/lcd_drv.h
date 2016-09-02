#include <avr/io.h>

#define D4PORT PORTD
#define D5PORT PORTC
#define D6PORT PORTD
#define D7PORT PORTE
#define RSPORT PORTB
#define ENPORT PORTB
#define BLPORT PORTB

#define D4 PORTD4
#define D5 PORTC6
#define D6 PORTD7
#define D7 PORTE6
#define RS PORTB4
#define EN PORTB5
#define BL PORTB6

void _hd44780_drv::init_lcd();
