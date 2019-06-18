make: exe input.txt
	./exe input.txt
exe: fun.o main.o
	gcc -g -o exe fun.o main.o
fun.o: fun.c
	gcc -g -c fun.c
main.o: main.c
	gcc -g -c main.c
