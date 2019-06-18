exe: driver.o quick.o stack.o
	gcc -g -o exe driver.o quick.o stack.o
driver.o: driver.c
	gcc -g -c driver.c
quick.o: quick.c
	gcc -g -c quick.c
stack.o:
	gcc -g -c stack.c
clean:
	rm *.o
