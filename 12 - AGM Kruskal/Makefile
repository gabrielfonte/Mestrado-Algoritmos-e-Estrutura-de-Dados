CC = g++
FLAGS += -std=c++14

INCLUDE_DIR = '${shell pwd}'

all:
	$(CC) -I$(INCLUDE_DIR) $(FLAGS) main.cpp -o main.o -c
	@echo "CC $<"

	$(CC) -o atividade_agm_kruskal $(FLAGS) main.o
	@echo "CC $<"

clean:
	rm -rf *.o

run:
	./atividade_agm_kruskal
