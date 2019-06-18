make: exe book.txt
	./exe book.txt
exe: main.o fun.o
	gcc -g -o exe main.o fun.o -lm
main.o: main.c fun.h
	gcc -g -c main.c -lm
fun.o: fun.c fun.h
	gcc -g -c fun.c -lm
