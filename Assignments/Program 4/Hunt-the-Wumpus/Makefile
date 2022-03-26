# Makefile for Hunt_the_wumpus.cpp

CC = g++ -Wall -g -std=c++11

exe_file = hunt_the_wumpus

$(exe_file): Event.o Wumpus.o Bats.o Pit.o Gold.o Room.o Game.o AI.o Hunt_the_wumpus.o
	$(CC) Event.o Wumpus.o Bats.o Pit.o Gold.o Room.o Game.o AI.o Hunt_the_wumpus.o -o $(exe_file)

Event.o: Event.cpp
	$(CC) -c Event.cpp

Wumpus.o: Wumpus.cpp
	$(CC) -c Wumpus.cpp

Bats.o: Bats.cpp
	$(CC) -c Bats.cpp

Pit.o: Pit.cpp
	$(CC) -c Pit.cpp

Gold.o: Gold.cpp
	$(CC) -c Gold.cpp

Room.o: Room.cpp
	$(CC) -c Room.cpp

Game.o: Game.cpp
	$(CC) -c Game.cpp

AI.o: AI.cpp
	$(CC) -c AI.cpp

clean:
	rm -f *.out *.o $(exe_file)

.PHONY: clean
