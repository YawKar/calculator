# Компилятор для C
CC=gcc

all: main

main: main.o CommandLineInterface.o ConsoleEngine.o Logger.o
	$(CC) main.o CommandLineInterface.o ConsoleEngine.o Logger.o -o Executable

main.o:
	$(CC) -c src/main.c -o main.o

CommandLineInterface.o:
	$(CC) -c src/ConsoleEngine/CommandLineInterface.c -o CommandLineInterface.o

ConsoleEngine.o:
	$(CC) -c src/ConsoleEngine/ConsoleEngine.c -o ConsoleEngine.o

Logger.o:
	$(CC) -c src/Logger/Logger.c -o Logger.o

clean:
	rm -rf *.o
