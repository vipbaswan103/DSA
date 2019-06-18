make: exe input
	./exe input
exe: driver.o fun.o fun.h
	gcc -g -o exe driver.o fun.o
driver.o: driver.c fun.h
	gcc -g -c driver.c
fun.o: fun.c fun.h
	gcc -g -c fun.c
clean:
	rm *.o exe
