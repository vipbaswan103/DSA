make: exe input.txt
	./exe input.txt
exe: cycle.o main.o
	gcc -g -o exe cycle.o main.o
cycle.o: cycle.c 
	gcc -g -c cycle.c
main.o: main.c
	gcc -g -c main.c
clean:
	rm *.o exe
