all: exe1 exe2
exe1: main.o Exer3.o hareTort.o
	gcc -g -o exe1 main.o Exer3.o hareTort.o
exe2: main.o Exer3.o revLink.o
	gcc -g -o exe2 main.o Exer3.o revLink.o
hareTort.o: hareTort.c
	gcc -c -g hareTort.c
revLink.o: revLink.c
	gcc -c -g revLink.c
main.o: main.c
	gcc -c -g main.c
Exer3.o: Exer3.c
	gcc -c -g Exer3.c
clean:
	rm *.o
cleanExe:
	rm exe1 exe2
