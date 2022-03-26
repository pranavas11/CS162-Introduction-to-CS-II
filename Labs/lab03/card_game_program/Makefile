# Makefile for driver.cpp

CC = g++ -std=c++11 -Wall -g
exe_file = card_game
$(exe_file): card.o deck.o card_game.o
	$(CC) card.o deck.o card_game.o -o $(exe_file)
card.o: card.cpp
	$(CC) -c card.cpp
deck.o: deck.cpp
	$(CC) -c deck.cpp
card_game.o: card_game.cpp
	$(CC) -c card_game.cpp

clean:
	rm -f *.out *.o output.* $(exe_file)