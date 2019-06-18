exe: driver.o fun.o
	gcc -g -o exe driver.o fun.o -pg
driver.o: driver.c
	gcc -c -g driver.c -pg
fun.o: fun.c
	gcc -c -g fun.c -pg
clear:
	rm *.o exe
