all: project1 project2
project1: lib.o main.o mystring.h test.txt
	cc lib.c main.c -o project1 -Wall
lib.o: lib.c mystring.h
	cc -c lib.c -Wall
main.o: mystring.h lib.c test.txt 
	cc -c main.c -Wall

project2: wchar.o main1.o mywchar.h test1.txt
	cc wchar.c main1.c -o project2 -Wall
wchar.o: wchar.c mywchar.h
	cc -c wchar.c -Wall
main1.o: wchar.c mywchar.h test1.txt
	cc -c main1.c -Wall
clean:
	rm lib.o main.o wchar.o main1.o
	rm -rf *o project1 project2
