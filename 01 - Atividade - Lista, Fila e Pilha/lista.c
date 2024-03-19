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

int Imprime_lista(struct Aluno *lista){
    /* Verifica se a lista é um endereço válido */    
    if(lista != NULL){
        printf("Lista de Alunos\n");

        /* Cria um ponteiro para percorrer a lista */
        struct Aluno *p_lista = lista->proximo;

        /* Cria um índice para mostrar a posicao de cada aluno na lista */
        int indice = 0;

        /* Percorre a lista até obter o último elemento */
        while(p_lista != NULL){
            printf("Aluno[%d]: %d\n", indice, p_lista->valor);
            indice++;
            p_lista = p_lista->proximo;
        }

        return SUCESSO;
    }

    return FALHA;
}

int Insere_lista(struct Aluno *lista, int num){
    /* Verifica se a lista é um endereço válido */    
    if(lista != NULL) {

        /* Cria um ponteiro para percorrer a lista */
        struct Aluno *p_lista = lista;

        /* Percorre a lista até obter o último elemento */
        while(p_lista->proximo != NULL){
            p_lista = p_lista->proximo;
        }

        /* Aloca memória para a inserção do novo elemento */
        p_lista->proximo = malloc(sizeof(struct Aluno));

        /* Insere o novo elemento */
        p_lista->proximo->valor = num;
        p_lista->proximo->proximo = NULL;

        return SUCESSO;
    }

    return FALHA;
}

int Remove_lista(struct Aluno *lista, int num){
    /* Verifica se a lista é um endereço válido */    
    if(lista != NULL){

        /* Cria um ponteiro para percorrer a lista */
        struct Aluno *p_lista = lista;

        /* Verificação se existe um elemento na lista */
        if(p_lista->proximo != NULL){
            /* Percorre a lista até obter o valor especificado ou a lista terminar - 
            NOTA: aqui usei prox->prox para percorrer ate o penultimo elemento da lista ou até o próximo elemento ser o valor desejado */
            while(p_lista->proximo->proximo != NULL && p_lista->proximo->valor != num){
                p_lista = p_lista->proximo;
            }
        }

        /* Remove o elemento da lista, caso este seja o valor especificado */
        if(p_lista->proximo->valor == num){
            printf("Removendo %d da lista\n", num);
            /* O elemento a ser removido é o próximo da lista */
            struct Aluno *p_remover = p_lista->proximo;
            /* Este elemento deve ser substituído pelo ponteiro do próximo, de forma a ligar a lista novamente */
            p_lista->proximo = p_remover->proximo;
            /* Desaloca a memória do elemento removido */
            free(p_remover);
        }

        return SUCESSO;
    }

    return FALHA;
}


int main(int argc, char *argv[]) {

	int opcao = 0;
	char numeros[BUFFER_SIZE];
	struct Aluno *lista_alunos = NULL;

	/* Criação do cabeça de lista */
	lista_alunos = malloc(sizeof(struct Aluno));
	lista_alunos->proximo = NULL;

	while(1){
    	printf("Digite 1 para inserir um valor na lista ou 2 para remover um valor da lista: ");
    	scanf("%d", &opcao);
        fflush(stdin);

    	if(opcao == INSERIR){
            printf("Digite um valor para inserir na lista: ");
            scanf("%[0-9-+, ]", numeros);
            char *num = strtok(numeros,", \n");
            while(num != NULL){
                int converted = atoi(num);
                Insere_lista(lista_alunos, converted);
                num = strtok(NULL,", \n");
            }
    	}
    	else if(opcao == REMOVER){
            printf("Digite um valor para remover da lista: ");
            scanf("%[0-9-+, ]", numeros);
            char *num = strtok(numeros,", \n");
            while(num != NULL){
                int converted = atoi(num);
                Remove_lista(lista_alunos, converted);
                num = strtok(NULL,", \n");
            }
    	}
    	else{
        	printf("Opção inválida\n");
        	return 1;
    	}

        Imprime_lista(lista_alunos);
	}
	return 0;
}
