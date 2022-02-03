# Компилятор для C
CC=clang-12
SRC=src

all: main

main: main.o
	$(CC) main.o -o main

main.o:
	$(CC) -c $(SRC)/main.c

clean:
	rm -rf *.o main
