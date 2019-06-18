test: exe $(N)
	./exe $(N)
exe: exer1.o imp.o
	gcc -g -o exe exer1.o imp.o -pg
exer1.o: exer1.c
	gcc -g -c exer1.c -pg
imp.o: imp.c
	gcc -g -c imp.c -pg
clean:
	rm *.o exe gmon.out
