main:proyecto2.o main.o
	gcc -Wall -o main proyecto2.o main.o
proyecto2.o:proyecto2.c proyecto2.h
	gcc -Wall -c -o proyecto2.o proyecto2.c
main.o:main.c proyecto2.h
	gcc -Wall -c -o main.o main.c
