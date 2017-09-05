
CC = g++

CFLAGS = -g -Wall

all: hw1

hw1: hw1.o
	$(CC) $(CFLAGS) -o hw1 hw1.cpp

clean: 
	-rm hw1