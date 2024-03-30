billing.out: main display input
	gcc main display input -o billing.out

display: display.c display.h
	gcc -c display.c -o display

input: input.h input.c
	gcc -c input.c -o input

main: main.c display.h input.h
	gcc -c main.c -o main

