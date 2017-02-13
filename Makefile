#############################################################
# Makefile for CS 530 Assignment #1 
# NOTE THIS WAS TAKEN FROM THE SAMPLE GIVEN TO US ON BLACKBOARD
# Matthew Yamout cssc1002
# James Hammon cssc0895
# February 12th, 2017
# CS 530 Spring 2017
# Assignment One Hexdump
# Makefile
#############################################################
EXEC = xsd
CC = g++
$(EXEC):
	$(CC) -std=c++11 assignment1.cpp -o $(EXEC)
	rm -f *.o
clean:
	rm -f *.o core a.out $(EXEC)
#########################[ EOF: Makefile ]###################