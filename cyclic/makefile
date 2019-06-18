make: exe input
	./exe input
exe: fun.o driver.o fun.h
	gcc -o exe driver.o fun.o
fun.o: fun.c fun.h
	gcc -c fun.c
driver.o: driver.c fun.h
	gcc -c driver.c
clean: 
	rm *.o
