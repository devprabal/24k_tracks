all:
	@gcc -Wall -Wextra -std=c11 -pedantic main.c -o main

clean:
	@rm -rf main
