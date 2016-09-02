#include "lcd_drv.h"
#include <util/delay.h>

class _hd44780_drv{
public:
  void init_lcd();
}

void _hd44780_drv::send_cmd(){

}

void _hd44780_drv::init_lcd(){
  RSPORT << (0 << RS);
  D7PORT << (0 << D7);
  D6PORT << (0 << D6);
  D5PORT << (1 << D5);
  D4PORT << (0 << D4);
  ENPORT << (1 << EN);
  ENPORT << (0 << EN);
}
