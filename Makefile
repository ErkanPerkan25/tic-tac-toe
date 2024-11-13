DEBUG = -g
CXXFLAGS = $(DEBUG) -Wall -ansi -pedantic -std=c++20
LDFLAGS = -c

CXX=g++ 

OBJS = tic_tac_toe.o 

.PHONY: all clean

all: tic_tac_toe

tic_tac_toe: tic_tac_toe.cpp
	$(CXX) $(CXXFLAGS) -o tic_tac_toe tic_tac_toe.cpp 

clean:
	/bin/rm -rf *~ $(OBJS) tic_tac_toe
