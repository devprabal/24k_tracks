BINARY = main

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:%.c=%.o)

%.o: %.c
	@gcc -Wall -Wextra -std=c11 -pedantic -I. -c $< -o $@

all: $(OBJECTS)
	@gcc -Wall -Wextra -std=c11 -pedantic $^ -o $(BINARY) 

clean:
	@rm -rf $(OBJECTS)
	@rm -rf $(BINARY) 

valgrind:
	@make clean
	@make all
	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(BINARY) 
