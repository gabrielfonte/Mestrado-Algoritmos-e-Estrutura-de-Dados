CC = g++
FLAGS += -std=c++11

INCLUDE_DIR = '${shell pwd}'

all:
	$(CC) -I$(INCLUDE_DIR) $(FLAGS) lista.cpp -o lista.o -c
	@echo "CC $<"

	$(CC) -I$(INCLUDE_DIR) $(FLAGS) pilha.cpp -o pilha.o -c
	@echo "CC $<"

	$(CC) -I$(INCLUDE_DIR) $(FLAGS) fila.cpp -o fila.o -c
	@echo "CC $<"

	$(CC) -I$(INCLUDE_DIR) $(FLAGS) main.cpp -o main.o -c
	@echo "CC $<"

	$(CC) -o atividade $(FLAGS) fila.o pilha.o lista.o main.o
	@echo "CC $<"

clean:
	rm -rf *.o

run:
	./atividade