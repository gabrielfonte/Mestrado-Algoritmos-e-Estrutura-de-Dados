//
// Created by Gabriel Fonte on 01/04/24.
//

#include <stdio.h>
#include <stdlib.h>

enum codigos_erro {
    SUCESSO,
    FALHA
};

struct Arvore {
    int valor;
    struct Arvore* esq;
    struct Arvore* dir;
    struct Arvore* pai;
};

typedef struct Arvore* Arv;

int Insere_Bin(Arv *arvore, int num){

    if((*arvore) == NULL){
        *arvore = malloc(sizeof(struct Arvore));
        (*arvore)->esq = NULL;
        (*arvore)->dir = NULL;
        (*arvore)->valor = num;
        return SUCESSO;
    }
    else if(num < (*arvore)->valor){
        printf("Esquerda\n");
        return Insere_Bin(&((*arvore)->esq), num);
    }
    else if(num > (*arvore)->valor){
        printf("Direita\n");
        return Insere_Bin(&((*arvore)->dir), num);
    }

    return FALHA;
}

int Remove_Bin(struct Arvore *arvore, int num){
    return FALHA;
}

int main(){

    /* Criação da Árvore */
    Arv arvore = NULL;

    Insere_Bin(&arvore, 5);
    Insere_Bin(&arvore, 10);
    Insere_Bin(&arvore, 7);

    return 0;
}