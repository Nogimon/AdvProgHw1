
CC = g++

CFLAGS = -g -Wall

TARGET = hw1

all: hw1

hw1: hw1.o
	$(CC) $(CFLAGS) -o hw1.out hw1.cpp

clean: 
	-rm hw1.out