BINARY = main

all:
	@gcc -Wall -Wextra -std=c11 -pedantic main.c -o $(BINARY) 

clean:
	@rm -rf $(BINARY) 

valgrind:
	@make clean
	@make all
	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(BINARY) 

