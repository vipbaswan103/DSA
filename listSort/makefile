make: exe input
	./exe input
exe: driver.o fun.o
	gcc -g -o exe driver.o fun.o
driver.o: driver.c
	gcc -g -c driver.c
fun.o: fun.c
	gcc -g -c fun.c
