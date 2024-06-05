CC = g++
FLAGS += -std=c++11

INCLUDE_DIR = '${shell pwd}'

all:
	$(CC) -I$(INCLUDE_DIR) $(FLAGS) HashTable.cpp -o hashtable.o -c
	@echo "CC $<"

	$(CC) -I$(INCLUDE_DIR) $(FLAGS) ListGenerator.cpp -o listgenerator.o -c
	@echo "CC $<"

	$(CC) -I$(INCLUDE_DIR) $(FLAGS) main.cpp -o main.o -c
	@echo "CC $<"

	$(CC) -o atividadehash $(FLAGS) hashtable.o listgenerator.o main.o
	@echo "CC $<"

clean:
	rm -rf *.o

run:
	./atividadehash