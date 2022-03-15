# Hey Emacs, this is a -*- makefile -*-
#----------------------------------------------------------------------------
# On command line:
#
# make all = Make software.
#
# make clean = Clean out built project files.
#
# make coff = Convert ELF to AVR COFF.
#
# make extcoff = Convert ELF to AVR Extended COFF.
#
# make program = Download the hex file to the device, using avrdude.
#                Please customize the avrdude settings below first!
#
# make debug = Start either simulavr or avarice as specified for debugging,
#              with avr-gdb or avr-insight as the front end for debugging.
#
# make filename.s = Just compile filename.c into the assembler code only.
#
# make filename.i = Create a preprocessed source file for use in submitting
#                   bug reports to the GCC project.
#
# To rebuild project do "make clean" then "make all".
#----------------------------------------------------------------------------
# Target file name (without extension).
# This is the name of the compiled .hex file.
TARGET = kyber

# List C source files here.
# Header files (.h) are automatically pulled in.
SRC += main.c
#SRC += aes-normal.c

# -----------------------------------------------------------------------------
# PLATFORM = CW303
PLATFORM = CW308_STM32F3
#PLATFORM = CW308_SAML11
# -----------------------------------------------------------------------------
SS_VER = SS_VER_1_1
# CRYPTO_TARGET = NONE

#Add simpleserial project to build
include ../base/simpleserial/Makefile.simpleserial

FIRMWAREPATH = ../base/.
include $(FIRMWAREPATH)/Makefile.inc
