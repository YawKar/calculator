all: main

main: main.o
	clang-12 main.o -o main

main.o:
	clang-12 -c src/main.c

clean:
	rm -rf *.o main
