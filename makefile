all: conv

conv: main.o conv.o
	gcc main.o conv.o -o conv -Wall -pedantic

main.o: main.c
	gcc -c main.c -o main.o -Wall -pedantic

config.o: conv.c
	gcc -c conv.c -o conv.o -Wall -pedantic

install:
	install conv /usr/bin

uninstall:
	rm -f /usr/bin/conv

clean:
	rm *.o
