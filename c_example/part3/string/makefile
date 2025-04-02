TARGET = myString

all : ${TARGET}

myString : main.o myString.o
	cc -o myString main.o myString.o

main.o : main.c myString.h
	cc -c main.c

myString.o : myString.c
	cc -c myString.c

clean :
	rm ${TARGET} main.o myString.o