try: lib.c main.c mystring.h
	cc -c lib.c -Wall 
	cc -c main.c -Wall
	cc lib.c main.c -o try -Wall
lib.o: mystring.h lib.c
	cc -c lib.c -Wall
main.o: mystring.h lib.c test.c
	cc -c main.c -Wall
clean:
	rm lib.o main.o
