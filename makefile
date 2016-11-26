CC = avr-gcc
AS = avr-as
OBJCOPY = avr-objcopy
LD = avr-ld

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[1;33m
CLEAR = \033[0m

heximage:
	clear
	@rm -f image.hex
	@echo "[ $(RED)RM$(CLEAR) ]" $@
	@$(CC) -mmcu=atmega32u4 -Os -o output.elf main.c
	@echo "[ $(GREEN)AVR-GCC$(CLEAR) ]" $@
	@$(OBJCOPY) -j .text -j .data -O ihex output.elf image.hex
	@echo "[ $(YELLOW)OBJCOPY$(CLEAR) ]" $@
	@rm output.elf
	@echo "[ $(RED)RM$(CLEAR) ]" $@
program:
	sudo avrdude -vvvvv -c avr109 -P $(SERPORT) -p m32u4 -b 57600 -V -Uflash:w:image.hex:i
