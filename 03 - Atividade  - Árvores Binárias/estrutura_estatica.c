//
// Created by Gabriel Fonte on 01/04/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE  512
#define MAX_ELEMENTS 100

#define print_line() printf("-------------------------------------------------\n")

enum opcoes {
    INSERIR = 1,
    REMOVER = 2,
};

enum codigos_erro {
    SUCESSO,
    FALHA
};

int Arvore[MAX_ELEMENTS];
typedef int Arv;

int Insere_Bin(Arv *arvore, int num){
    if(arvore != NULL){
        if(num < arvore[0]){

        }
        else if(num > arvore[0]){
            printf("Inserindo %d\n", num);
        }
        else if(num == arvore[0]){
            printf("Valor já existe na árvore\n");
        }
    }
    else if(num < (*arvore)->valor){
        return Insere_Bin(&((*arvore)->esq), num);
    }
    else if(num > (*arvore)->valor){
        return Insere_Bin(&((*arvore)->dir), num);
    }

    return FALHA;
}

int Remove_Bin(Arv *arvore, int num){
    if((*arvore) != NULL){
        if(num < (*arvore)->valor) {
            Remove_Bin(&((*arvore)->esq), num);
        }
        else if(num > (*arvore)->valor){
            Remove_Bin(&((*arvore)->dir), num);
        }
        else{
            printf("Removendo %d\n", (*arvore)->valor);
            /* Subárvore esquerda e direita são nulas, portanto é só fazer a remoção do nó */
            if((*arvore)->esq == NULL && (*arvore)->dir == NULL){
                free(*arvore); // Remove o nó
                *arvore = NULL; // Atribui o NULL, sinalizando que pode ser inserido um novo valor
            }
                /* Apenas a subárvore esquerda é nula, portanto o valor apontado pela subárvore é substituído */
            else if((*arvore)->esq == NULL) {
                Arv aux = *arvore; // Guarda o valor do nó a ser removido
                *arvore = (*arvore)->dir; // Substitui o valor do nó a ser removido pelo valor da subárvore direita
                free(aux); // Libera o valor do nó a ser removido
            }
                /* Apenas a subárvore direita é nula, portanto o valor apontado pela subárvore é substituído */
            else if((*arvore)->dir == NULL){
                Arv aux = *arvore; // Guarda o valor do nó a ser removido
                *arvore = (*arvore)->esq; // Substitui o valor do nó a ser removido pelo valor da subárvore esquerda
                free(aux); // Libera o valor do nó a ser removido
            }
                /* Nenhuma das subárvores são nulas */
            else if((*arvore)->esq != NULL && (*arvore)->dir != NULL){
                Arv aux = *arvore; // Guarda o valor do nó a ser removido
                Arv aux2 = (*arvore)-> esq; // Guarda o valor da subárvore esquerda
                /* Procura o maior valor na subárvore esquerda*/
                while(aux->dir != NULL){
                    aux2 = aux2->dir;
                }
                *arvore = aux2;
                free(aux); // Libera o valor do nó a ser removido
            }
            return SUCESSO;
        }
    }

    return FALHA;
}

void Pre_Ordem(Arv *arvore){
    if((*arvore) != NULL){
        printf("%d\n", (*arvore)->valor);
        Pre_Ordem(&(*arvore)->esq);
        Pre_Ordem(&(*arvore)->dir);
    }
}

void In_Ordem(Arv *arvore){
    if((*arvore) != NULL){
        In_Ordem(&(*arvore)->esq);
        printf("%d\n", (*arvore)->valor);
        In_Ordem(&(*arvore)->dir);
    }
}

void Pos_Ordem(Arv *arvore){
    if((*arvore) != NULL){
        Pos_Ordem(&(*arvore)->esq);
        Pos_Ordem(&(*arvore)->dir);
        printf("%d\n", (*arvore)->valor);
    }
}

int main(){

    int opcao = 0;
    char numeros[BUFFER_SIZE];

    /* Criação da Árvore */
    Arv arvore = NULL;

    while(1){
        print_line();
        printf("Digite 1 para inserir um valor na árvore ou 2 para remover um valor da árvore: ");
        scanf("%d", &opcao);
        while (getchar() != '\n'); // Limpa o buffer do teclado

        if(opcao == INSERIR){
            printf("Digite um valor para inserir na árvore: ");
            scanf("%[0-9-+, ]", numeros);
            char *num = strtok(numeros,", \n");
            while(num != NULL){
                int converted = atoi(num);
                Insere_Bin(&arvore, converted);
                num = strtok(NULL,", \n");
            }
        }
        else if(opcao == REMOVER){
            printf("Digite um valor para remover da árvore: ");
            scanf("%[0-9-+, ]", numeros);
            char *num = strtok(numeros,", \n");
            while(num != NULL){
                int converted = atoi(num);
                Remove_Bin(&arvore, converted);
                num = strtok(NULL,", \n");
            }
        }
        else{
            printf("Opção inválida\n");
            return 1;
        }

        printf("Pre Ordem:\n");
        Pre_Ordem(&arvore);

        printf("In Ordem:\n");
        In_Ordem(&arvore);

        printf("Pos Ordem:\n");
        Pos_Ordem(&arvore);
    }

    return 0;
}