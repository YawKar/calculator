# Компилятор для C
CC = gcc

rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

ALL_CSOURCES:=$(call rwildcard,src/,*.c)
ALL_OBJECTS:=$(call rwildcard,./,*.o)

all:

link:
	gcc $(ALL_OBJECTS) -o Exec -lm

compile:
	gcc -c $(ALL_CSOURCES)

clean:
	rm -Rf *.o

help:
	@echo $(ALL_OBJECTS)