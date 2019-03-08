10: exe input10.txt
	./exe input10.txt
100: exe input100.txt
	./exe input100.txt
10000: exe input10000.txt
	./exe input10000.txt
exe: multiq.o driver.o multiq.h
	gcc -o exe multiq.o driver.o -g -pg
multiq.o: multiq.c multiq.h
	gcc -g -c multiq.c -pg
driver.o: driver.c multiq.h
	gcc -g -c driver.c -pg
