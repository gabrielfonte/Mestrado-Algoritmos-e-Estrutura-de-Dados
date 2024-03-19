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

int Imprime_pilha(struct Aluno *pilha){
    /* Verifica se a pilha é um endereço válido */    
    if(pilha != NULL){
        printf("Pilha de Alunos\n");

        /* Cria um ponteiro para percorrer a pilha */
        struct Aluno *p_pilha = pilha->proximo;

        /* Cria um índice para mostrar a posicao de cada aluno na pilha */
        int indice = 0;

        /* Percorre a pilha até obter o último elemento */
        while(p_pilha != NULL){
            printf("Aluno[%d]: %d\n", indice, p_pilha->valor);
            indice++;
            p_pilha = p_pilha->proximo;
        }

        return SUCESSO;
    }

    return FALHA;
}

int Insere_pilha(struct Aluno *pilha, int num){
    /* Verifica se a pilha é um endereço válido */    
    if(pilha != NULL) {

        /* Cria um ponteiro para percorrer a pilha */
        struct Aluno *p_pilha = pilha;

        /* Percorre a pilha até obter o último elemento */
        while(p_pilha->proximo != NULL){
            p_pilha = p_pilha->proximo;
        }

        /* Aloca memória para a inserção do novo elemento */
        p_pilha->proximo = malloc(sizeof(struct Aluno));

        /* Insere o novo elemento */
        p_pilha->proximo->valor = num;
        p_pilha->proximo->proximo = NULL;

        return SUCESSO;
    }

    return FALHA;
}

int Remove_pilha(struct Aluno *pilha, int *elemento_removido){
    /* Verifica se a pilha é um endereço válido */    
    if(pilha != NULL){

        /* Cria um ponteiro para percorrer a pilha */
        struct Aluno *p_pilha = pilha;

        /* Verificação se existe um elemento na pilha */
        if(p_pilha->proximo != NULL){
            /* Percorre a pilha até o final */
            while(p_pilha->proximo->proximo != NULL){
                p_pilha = p_pilha->proximo;
            }
        }

        /* Remove o valor da pilha */
        if(p_pilha->proximo != NULL){
            int valor = p_pilha->proximo->valor;
            printf("Removendo %d da pilha\n", p_pilha->proximo->valor);
            /* O elemento a ser removido é o próximo da pilha */
            struct Aluno *p_remover = p_pilha->proximo;
            /* Este elemento deve ser substituído pelo ponteiro do próximo, de forma a ligar a estrutura novamente */
            p_pilha->proximo = p_remover->proximo;
            /* Desaloca a memória do elemento removido */
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
	struct Aluno *pilha_alunos = NULL;

	/* Criação do cabeça de pilha */
	pilha_alunos = malloc(sizeof(struct Aluno));
	pilha_alunos->proximo = NULL;

	while(1){
    	printf("Digite 1 para inserir um valor na pilha ou 2 para remover um valor da pilha: ");
    	scanf("%d", &opcao);
        while (getchar() != '\n'); // Limpa o buffer do teclado

    	if(opcao == INSERIR){
            printf("Digite um valor para inserir na pilha: ");
            scanf("%[0-9-+, ]", numeros);

            char *num = strtok(numeros,", \n");
            while(num != NULL){
                int converted = atoi(num);
                Insere_pilha(pilha_alunos, converted);
                num = strtok(NULL,", \n");
            }
    	}
    	else if(opcao == REMOVER){
            int elemento_removido;
            if(Remove_pilha(pilha_alunos, &elemento_removido) == SUCESSO) {
                printf("Elemento removido: %d\n", elemento_removido);
            }
            else {
                printf("Pilha vazia\n");
            }
    	}
    	else{
        	printf("Opção inválida\n");
        	return 1;
    	}

        Imprime_pilha(pilha_alunos);
	}
	return 0;
}
