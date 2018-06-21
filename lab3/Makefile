OBJ = build/dijkstra.o build/heap.o build/graph.o build/main.o
CC = gcc
CFLAGS  = -Wall -Werror -std=c99

.PHONY: clean open

bin/Dijkstra_prog: $(OBJ) bin
	$(CC) $(CFLAGS) -o bin/Dijkstra_prog $(OBJ) -lm

build/dijkstra.o: src/dijkstra.c build
	$(CC) $(CFLAGS) -o build/dijkstra.o -c src/dijkstra.c -lm

build/heap.o: src/heap.c build
	$(CC) $(CFLAGS) -o build/heap.o -c src/heap.c -lm

build/main.o: src/main.c build
	$(CC) $(CFLAGS) -o build/main.o -c src/main.c -lm

build/graph.o: src/graph.c build
	$(CC) $(CFLAGS) -o build/graph.o -c src/graph.c -lm

build:
	mkdir build

bin:
	mkdir bin

clean :
	rm -rf build bin
open :
	./bin/Dijkstra_prog