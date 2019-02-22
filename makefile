all: conv

conv: main.o config.o
	gcc main.o config.o -o conv

main.o: main.c
	gcc -c main.c -o main.o

config.o: config.c
	gcc -c config.c -o config.o

clean:
	rm *.o