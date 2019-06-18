exe2: driver.o fun.o iter.o
	gcc -g -o exe2 driver.o fun.o iter.o -lm
iter.o: iter.c
	gcc -g -c iter.c -lm
driver.o: driver.c
	gcc -g -c driver.c -lm
fun.o: fun.c
	gcc -g -c fun.c -lm
recur.o: recur.c
	gcc -g -c recur.c -lm
clean: 
	rm *.o 
