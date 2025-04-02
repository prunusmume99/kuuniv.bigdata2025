TARGET = myRandom

all : ${TARGET}

myRandom : main.o myRandom.o
	cc -o myRandom main.o myRandom.o

main.o : main.c myRandom.h
	cc -c main.c

myRandom.o : myRandom.c
	cc -c myRandom.c

clean : 
	rm ${TARGET} main.o myRandom.o