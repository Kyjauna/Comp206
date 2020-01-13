bank: main.o ssv.o linked.o
	gcc -o bank main.o ssv.o linked.o
main.o: main.c ssv.h linked.h
	gcc -c main.c
ssv.o: ssv.c ssv.h
	gcc -c ssv.c
linked.o: linked.c ssv.c
	gcc -c linked.c
