#############################################################
# SAMPLE Makefile for CSNNN Assignment #n
# Guy Leonard
#############################################################
EXEC = xsd
CC = g++
$(EXEC):
	$(CC) -std=c++11 assignment1.cpp -o $(EXEC)
	rm -f *.o
clean:
	rm -f *.o core a.out $(EXEC)
#########################[ EOF: Makefile ]###################
