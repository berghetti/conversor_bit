all: conv

conv: main.o conv.o
	gcc main.o conv.o -o conv

main.o: main.c
	gcc -c main.c -o main.o

config.o: conv.c
	gcc -c conv.c -o conv.o

clean:
	rm *.o