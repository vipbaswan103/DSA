compIter: driver.o iter.o fun.o fun.h
	gcc -g -o iter fun.o iter.o driver.o -lm
compRec: driver.o fun.o recur.o fun.h
	gcc -g -o rec fun.o recur.o driver.o -lm
recur.o: recur.c fun.h
	gcc -g -c recur.c -lm
iter.o: iter.c fun.h 
	gcc -g -c iter.c -lm
driver.o: driver.c fun.h
	gcc -g -c driver.c -lm
fun.o: fun.c fun.h
	gcc -g -c fun.c -lm
clean:
	rm *.o
