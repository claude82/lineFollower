# File:   Makefile
# Author: Claude Meffan, Student
# Date:   5 June 2013
# Descr:  Makefile for lineFollower

# Definitions.
CC = avr-gcc
CFLAGS = -mmcu=atmega32u2 -Os -Wall -Wstrict-prototypes -Wextra -g -I../../drivers/avr -I../../utils
OBJCOPY = avr-objcopy
SIZE = avr-size
DEL = rm


# Default target.
all: lineFollower.out


# Compile: create object files from C source files.
main.o: main.c ../../ucfk4/drivers/avr/pio.h
	$(CC) -c $(CFLAGS) $< -o $@

pio.o: ../../ucfk4/drivers/avr/pio.c ../../ucfk4/drivers/avr/pio.h ../../ucfk4/drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

system.o: ../../ucfk4/drivers/avr/system.c ../../ucfk4/drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

# Link: create output file (executable) from object files.
lineFollower.out: main.o pio.o system.o
	$(CC) $(CFLAGS) $^ -o $@ -lm
	$(SIZE) $@


# Target: clean project.
.PHONY: clean
clean: 
	-$(DEL) *.o *.out *.hex


# Target: program project.
.PHONY: program
program: lineFollower.out
	$(OBJCOPY) -O ihex lineFollower.out lineFollower.hex
	dfu-programmer atmega32u2 erase; dfu-programmer atmega32u2 flash lineFollower.hex; dfu-programmer atmega32u2 start


