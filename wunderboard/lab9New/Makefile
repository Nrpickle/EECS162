# Hey Emacs, this is a -*- makefile -*-
# Bennett Rand
# June 2013
# CS162

# Target file name
TARGET = main

# List of C source files and object files
SRC =	$(TARGET).c \
	wunder.c \
	usart.o \
	adc.o \
	leds.o

# Executable names
COMPILER = avr-gcc
COPY = avr-objcopy
DFU = dfu-programmer

# Which chip to program for
CHIP = at90usb1287
DEV = /dev/ttyACM0

# Helptext to print for help target
HLP = "This is help text.\n"\
"More help."

# Generated user string
USER = $(shell whoami)

#Avrdude variables
AVR_D = avrdude
AVR_D_FLAGS = -c AVR109 -p $(CHIP) -P $(DEV) -vv -B 10
ERASE = -e
FLASH = -U flash:w:"$(TARGET).hex"

# Misc arguments
FRQ = 8000000
DEFS = -Wp,-DF_CPU=$(FRQ)UL
LIBS = -lm
OPT = s #s = size, 0 = none, 3 = maximum
STD = gnu99

version:
	@echo =====Version=====
	@$(COMPILER) --version
	@echo =================

help:
	@echo =====Help=====
	@echo $(HLP)

build: version
	@echo =====Compiling=====
	$(COMPILER) -mmcu=$(CHIP) $(DEFS) -O$(OPT) $(LIBS) -std=$(STD) $(SRC) -o $(TARGET).elf
	@echo =====Making .hex File=====
	$(COPY) -O ihex -R .eeprom -R .fuse -R .lock -R .signature $(TARGET).elf $(TARGET).hex
	@echo =====Build Done=====

build-pedantic: version
	@echo =====Compiling=====
	$(COMPILER) -mmcu=$(CHIP) $(DEFS) -O$(OPT) $(LIBS) -std=$(STD) --pedantic  $(SRC) -o $(TARGET).elf
	@echo =====Making .hex File=====
	$(COPY) -O ihex -R .eeprom -R .fuse -R .lock -R .signature $(TARGET).elf $(TARGET).hex
	@echo =====Pedantic Build Done=====

device:
	@echo =====Testing for Wunderboard=====
	test -e $(DEV)
	@echo =====Wunderboard Found=====

superuser:
	@echo =====Testing for root=====
	@echo =====Running as $(USER)=====
	@test $(USER) = root

program: program_new
	@echo

program_new: superuser build
	@echo =====Programming Board=====
	$(AVR_D) $(AVR_D_FLAGS) $(ERASE) $(FLASH)
	@echo =====Programming Done=====

clean:
	@echo =====Cleaning=====
	rm $(TARGET).elf $(TARGET).hex

rebuild: clean build
rebuild-pedantic: clean build-pedantic
default: build