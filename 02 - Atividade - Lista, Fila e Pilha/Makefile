CC = g++

INCLUDE_DIR = '${shell pwd}'

%.o: %.c
	@$(CC) -I$(INCLUDE_DIR) -c -g $< -o $@
	@echo "CC $<"

all:
	$(CC) -I$(INCLUDE_DIR) lista.cpp -o lista.o -c
	@echo "CC $<"

	$(CC) -I$(INCLUDE_DIR) pilha.cpp -o pilha.o -c
	@echo "CC $<"

	$(CC) -I$(INCLUDE_DIR) main.cpp -o main.o -c
	@echo "CC $<"

	$(CC) -o atividade pilha.o lista.o main.o
	@echo "CC $<"

lista:
	$(CC) lista.cpp -o lista.o

fila:
	$(CC) fila.cpp -o fila.o

pilha:
	$(CC) pilha.cpp -o pilha.o

clean:
	rm -rf *.o