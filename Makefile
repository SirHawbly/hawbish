CC = clang++
CFLAGS = -std=c++17 -Wall -Werror -O3 -ferror-limit=5

all: repl.o main.o
	@echo "\ncleaning out obj files ..."
	rm -rf src
	
	@echo "\nmaking a new src directory ..."
	mkdir src
	mv *.o src/
	
	@echo "\nrunning main ..."
	@src/main.o

repl.o: repl.cpp repl.h
	$(CC) $(CFLAGS) -c repl.cpp -o repl.o

main.o: main.cpp repl.o
	$(CC) $(CFLAGS) main.cpp -o main.o

clean:
	rm -rf src
