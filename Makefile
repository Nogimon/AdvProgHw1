
CC = g++

CFLAGS = --std=c++11 -Wall

TARGET = hw1

all: hw1

hw1: hw1.o
	$(CC) $(CFLAGS) -o hw1 hw1.cpp

clean: 
	-rm hw1