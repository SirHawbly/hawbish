#
# Copyright (c) 2019 Christopher Bartlett
# [This program is licensed under the "MIT License"]
# Please see the file LICENSE in the source
# distribution of this software for license terms.
#

CC = clang++
CFLAGS = -std=c++17 -Wall -Werror -O3 -ferror-limit=5 #-v

all: repl.o mal.o main.o
	$(CC) $(CFLAGS) -o main *.o 

	@echo "\ncleaning out obj files ..."
	rm -rf src
	
	@echo "\nmaking a new src directory ..."
	mkdir src
	mv *.o src/
	mv main src/
	
	@echo "\nrunning main ..."
	@src/main

repl.o: repl.cpp repl.h
	$(CC) $(CFLAGS) -c repl.cpp -o repl.o

mal.o: mal.cpp mal.h
	$(CC) $(CFLAGS) -c mal.cpp -o mal.o

main.o: main.cpp repl.o
	$(CC) $(CFLAGS) -c main.cpp -o main.o

clean:
	rm -rf src
