# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
% make
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o Resturants.o
    $(CC) $(CFLAGS) -o main main.o Resturants.o
 
# The main.o target can be written more simply
 
main.o: src/main.cpp lib/Resturants.h
    $(CC) $(CFLAGS) -c src/main.cpp
 
Resturants.o: Resturants.h
 
