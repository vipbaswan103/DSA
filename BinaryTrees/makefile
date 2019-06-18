make: exe input.txt
	./exe input.txt
exe: main.o fun.o fun.h
	gcc -g -o exe main.o fun.o
main.o: main.c fun.h
	gcc -g -c main.c
fun.o: fun.c fun.h
	gcc -g -c fun.c
clean:
	rm *.o exe
