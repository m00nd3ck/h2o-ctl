#include "disp.h"

void disp_cmd(char disp_cmd) {
  char command_scratchpad = (disp_cmd & 0b11110000); //we only need the top bits for now

  pcf_send(PCF_ADDR,command_scratchpad | (BL_STATE << BL));
  pcf_send(PCF_ADDR,command_scratchpad | (1 << EN) | (BL_STATE << BL));
  pcf_send(PCF_ADDR,command_scratchpad | (0 << EN) | (BL_STATE << BL));
  pcf_send(PCF_ADDR,0x00 | (BL_STATE << BL));

  command_scratchpad = ((disp_cmd & 0b00001111) << 4); //we only need the top bits for now
  
  pcf_send(PCF_ADDR,command_scratchpad | (BL_STATE << BL));
  pcf_send(PCF_ADDR,command_scratchpad | (1 << EN) | (BL_STATE << BL));
  pcf_send(PCF_ADDR,command_scratchpad | (0 << EN) | (BL_STATE << BL));
  pcf_send(PCF_ADDR,0x00 | (BL_STATE << BL));
}

void disp_init_4bit() {

  pcf_send(PCF_ADDR,(0b00100000 | (BL_STATE << BL)));
  pcf_send(PCF_ADDR,(0b00100000 | (1 << EN) | (BL_STATE << BL)));
  pcf_send(PCF_ADDR,(0b00100000 | (0 << EN) | (BL_STATE << BL)));
  pcf_send(PCF_ADDR,0x00 | (BL_STATE << BL));

  disp_cmd(0b00101000); //4 bit function set, 2 lines
  disp_cmd(0b00001110); //no cursor visible, no blink
  disp_cmd(0b00000110); //
  disp_cmd(0b00000010);
  
}

void disp_char(char character) {
  char char_scratchpad = (character & 0b11110000); //we only need the top bits for now

  pcf_send(PCF_ADDR,char_scratchpad | (BL_STATE << BL) | (1 << RS));
  pcf_send(PCF_ADDR,char_scratchpad | (1 << EN) | (BL_STATE << BL) | (1 << RS));
  pcf_send(PCF_ADDR,char_scratchpad | (0 << EN) | (BL_STATE << BL) | (1 << RS));
  pcf_send(PCF_ADDR,0x00 | (BL_STATE << BL) | (1 << RS));

  char_scratchpad = ((character & 0b00001111) << 4); //we only need the top bits for now
  
  pcf_send(PCF_ADDR,char_scratchpad | (BL_STATE << BL) | (1 << RS));
  pcf_send(PCF_ADDR,char_scratchpad | (1 << EN) | (BL_STATE << BL) | (1 << RS));
  pcf_send(PCF_ADDR,char_scratchpad | (0 << EN) | (BL_STATE << BL) | (1 << RS));
  pcf_send(PCF_ADDR,0x00 | (BL_STATE << BL) | (1 << RS));
}

void disp_out(char *string) {
  while(*string != 0) {
    disp_char(*string);
    string++;
  }
}

void disp_clr(void) {
  disp_cmd(0b00000010);
}