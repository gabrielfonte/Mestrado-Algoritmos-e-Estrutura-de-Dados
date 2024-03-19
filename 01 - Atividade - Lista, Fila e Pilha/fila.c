#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

enum opcoes {
	INSERIR = 1,
	REMOVER = 2,
};

enum codigos_erro {
    SUCESSO,
    FALHA
};

struct Aluno {
	int valor;
	struct Aluno *proximo;
};

int Imprime_fila(struct Aluno *fila){
    /* Verifica se a fila é um endereço válido */    
    if(fila != NULL){
        printf("Fila de Alunos\n");

        /* Cria um ponteiro para percorrer a fila */
        struct Aluno *p_fila = fila->proximo;

        /* Cria um índice para mostrar a posicao de cada aluno na fila */
        int indice = 0;

        /* Percorre a fila até obter o último elemento */
        while(p_fila != NULL){
            printf("Aluno[%d]: %d\n", indice, p_fila->valor);
            indice++;
            p_fila = p_fila->proximo;
        }

        return SUCESSO;
    }

    return FALHA;
}

int Insere_fila(struct Aluno *fila, int num){
    /* Verifica se a fila é um endereço válido */    
    if(fila != NULL) {

        /* Cria um ponteiro para percorrer a fila */
        struct Aluno *p_fila = fila;

        /* Percorre a fila até obter o último elemento */
        while(p_fila->proximo != NULL){
            p_fila = p_fila->proximo;
        }

        /* Aloca memória para a inserção do novo elemento */
        p_fila->proximo = malloc(sizeof(struct Aluno));

        /* Insere o novo elemento */
        p_fila->proximo->valor = num;
        p_fila->proximo->proximo = NULL;

        return SUCESSO;
    }

    return FALHA;
}

int Remove_fila(struct Aluno *fila, int *elemento_removido){
    /* Verifica se a fila é um endereço válido */    
    if(fila != NULL){

        /* Cria um ponteiro para percorrer a fila */
        struct Aluno *p_fila = fila;

        /* Remove o valor da fila - NOTA: Na estrutura fila, remove-se o valor inserido primeiro, portanto não é necessário percorrer a estrutura inteira */
        if(p_fila->proximo != NULL){
            int valor = p_fila->proximo->valor;
            printf("Removendo %d da fila\n", valor);
            /* Atribui a um ponteiro o elemento a ser removido */
            struct Aluno *p_remover = p_fila->proximo;
            /* Este elemento deve ser substituído pelo ponteiro do próximo, de forma a ligar a estrutura novamente */
            p_fila->proximo = p_remover->proximo;
            /* Libera a memória do elemento */
            free(p_remover);
            /* Atribui o valor a variável elemento removido */
            *elemento_removido = valor;
            return SUCESSO;
        }
    }

    return FALHA;
}


int main(int argc, char *argv[]) {

	int opcao = 0;
	char numeros[BUFFER_SIZE];
	struct Aluno *fila_alunos = NULL;

	/* Criação do cabeça de fila */
	fila_alunos = malloc(sizeof(struct Aluno));
	fila_alunos->proximo = NULL;

	while(1){
    	printf("Digite 1 para inserir um valor na fila ou 2 para remover um valor da fila: ");
    	scanf("%d", &opcao);
        while (getchar() != '\n'); // Limpa o buffer do teclado

    	if(opcao == INSERIR){
	    printf("Digite um valor para inserir na fila: ");
            scanf("%[0-9-+, ]", numeros);
            char *num = strtok(numeros,", \n");
            while(num != NULL){
                int converted = atoi(num);
                Insere_fila(fila_alunos, converted);
                num = strtok(NULL,", \n");
            }
    	}
    	else if(opcao == REMOVER){
            int elemento_removido;
            if(Remove_fila(fila_alunos, &elemento_removido) == SUCESSO) {
                printf("Elemento removido: %d\n", elemento_removido);
            }
            else {
                printf("Fila vazia\n");
            }
    	}
    	else{
        	printf("Opção inválida\n");
        	return 1;
    	}

        Imprime_fila(fila_alunos);
	}
	return 0;
}
