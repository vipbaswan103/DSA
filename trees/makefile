make: exe input
	./exe input
exe: driver.o fun.o fun.h
	gcc -o exe driver.o fun.o
driver.o: driver.c fun.h
	gcc -c driver.c
fun.o: fun.c fun.h
	gcc -c fun.c
