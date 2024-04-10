CC = g++
FLAGS += -std=c++17

INCLUDE_DIR = '${shell pwd}'
GRAPH_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all:
	$(CC) -I$(INCLUDE_DIR) $(FLAGS) $(GRAPH_FLAGS) arvore_avl_com_grafico.cpp -o arvore_avl_com_grafico
	@echo "CC $<"

	$(CC) -I$(INCLUDE_DIR) $(FLAGS) arvore_avl.c -o arvore_avl
	@echo "CC $<"

arvore_avl:
	$(CC) -I$(INCLUDE_DIR) $(FLAGS) arvore_avl.c -o arvore_avl
	@echo "CC $<"

arvore_avl_grafico:
	$(CC) -I$(INCLUDE_DIR) $(FLAGS) arvore_avl_com_grafico.cpp -o arvore_avl_com_grafico
	@echo "CC $<"