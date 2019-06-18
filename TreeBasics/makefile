make: exe input.txt
	./exe input.txt
exe: main.o fun.o
	gcc -g -o exe main.o fun.o
main.o: main.c
	gcc -g -c main.c
fun.o: fun.c
	gcc -g -c fun.c
clean:
	rm *.o exe
