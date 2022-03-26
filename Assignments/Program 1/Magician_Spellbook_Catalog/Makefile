# Makefile for magician_spellbook_catalog.cpp

CC = g++ -g -Wall -std=c++11
exe_file = spellbook_catalog

$(exe_file): spellbook_catalog.o magician_spellbook_catalog.o
	$(CC) spellbook_catalog.o magician_spellbook_catalog.o -o $(exe_file)

spellbook_catalog.o: spellbook_catalog.cpp
	$(CC) -c spellbook_catalog.cpp

magician_spellbook_catalog.o: magician_spellbook_catalog.cpp
	$(CC) -c magician_spellbook_catalog.cpp

clean:
	rm -f *.out *.o output.* $$(exe_file)

valgrind:
	valgrind --leak-check=full $(exe_file)
