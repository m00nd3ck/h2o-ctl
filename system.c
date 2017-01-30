#include "system.h"

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