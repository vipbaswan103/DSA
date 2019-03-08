make: exe input.txt
	./exe input.txt
exe: que.o driver.o
	gcc -g -o exe que.o driver.o

que.o: que.c que.h
	gcc -g -c que.c

driver.o: driver.c que.h
	gcc -g -c driver.c

