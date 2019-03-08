exe: multiq.o que.o test.o multiq.h que.h
	gcc -g -o exe multiq.o que.o test.o
test.o: test.c
	gcc -g -c test.c
multiq.o: multiq.c
	gcc -g -c multiq.c
que.o: que.c
	gcc -g -c que.c
clean:
	rm *.o
