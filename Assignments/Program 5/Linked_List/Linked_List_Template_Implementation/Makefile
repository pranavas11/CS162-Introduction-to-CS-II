# Makefile for Linked_List_Program.cpp

CC = g++ -Wall -Wextra -Werror -Wfatal-errors -pedantic -g -std=c++11

exe_file = linked_list

$(exe_file): Linked_List_Program.cpp
	$(CC) $^ -o $@

rm_obj_files:
	@rm -f *.out *.o $(exe_file)
	
clean: rm_obj_files $(exe_file)

.PHONY: clean rm_obj_files
