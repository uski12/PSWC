billing.out: main display input search
	gcc main display input search -o billing.out

search: search.c search.h
	gcc -c search.c -o search

display: display.c display.h structs.h
	gcc -c display.c -o display

input: input.h input.c structs.h
	gcc -c input.c -o input

main: main.c display.h input.h structs.h search.h
	gcc -c main.c -o main
