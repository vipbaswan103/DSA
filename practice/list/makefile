exe: driver.o list.o list.h
	gcc -g -o exe driver.o list.o 
driver.o: driver.c list.h
	gcc -g -c driver.c
list.o: list.c list.h
	gcc -g -c list.c
clean:
	rm *.o
