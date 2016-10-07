#include "lcd_drv.hpp"

#define F_CPU 160000000

class _hd44780_drv{
public:
  void init_lcd();
  void send_cmd(char rs,char data);
}

void _hd44780_drv::send_cmd(char rs,char data){
  RSPORT << (rs << RS);
  D7PORT << ((data >> 7) << D7);
  D6PORT << ((data >> 6) << D6);
  D5PORT << ((data >> 5) << D5);
  D4PORT << ((data >> 4) << D4);
  _delay_ms(1);
  ENPORT << (1 << EN);
  _delay_ms(1);
  ENPORT << (0 << EN);
  D7PORT << ((data >> 3) << D7);
  D6PORT << ((data >> 2) << D6);
  D5PORT << ((data >> 1) << D5);
  D4PORT << ((data) << D4);
  _delay_ms(1);
  ENPORT << (1 << EN);
  _delay_ms(1);
  ENPORT << (0 << EN);
}

void _hd44780_drv::init_lcd(){
  RSPORT << (0 << RS);
  D7PORT << (0 << D7);
  D6PORT << (0 << D6);
  D5PORT << (1 << D5);
  D4PORT << (0 << D4);
  ENPORT << (1 << EN);
  _delay_ms(1);
  ENPORT << (0 << EN);
  _delay_ms(1);
}
