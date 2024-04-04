//
// Created by Gabriel Fonte on 01/04/24.
//
// Estrutura de árvore em vetor baseada no livro Estrutura de Dados Usando C - TENEMBAUM M. Aaron et. al, 1995. pg. 325-330
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 512
#define NUM_NODES   500

#define print_line() printf("\n-------------------------------------------------\n")

#define ESQ(n) 2*n+1
#define DIR(n) 2*n+2

#define INDICE_RAIZ 0

enum opcoes {
    INSERIR = 1,
    REMOVER = 2,
};

enum codigos_erro {
    SUCESSO,
    FALHA
};

struct Arvore {
    int valor;
    bool usado;
};

void cria_arvore(struct Arvore *arvore, int number){
    int p;
    arvore[0].valor = number;
    arvore[0].usado = true;
    for(p = 1; p < NUM_NODES; p++){
        arvore[p].usado = false;
    }
}

void insere_esquerda(struct Arvore *arvore, int p, int number){
    int q;
    q = ESQ(p);
    if(q >= NUM_NODES){
        printf("Estouro do vetor\n");
        exit(1);
    }
    else if(arvore[q].usado){
        printf("Insercao incorreta\n");
        exit(1);
    }
    else {
        arvore[q].valor = number;
        arvore[q].usado = true;
    }
}

void insere_direita(struct Arvore *arvore, int p, int number){
    int q;
    q = DIR(p);
    if(q >= NUM_NODES){
        printf("Estouro do vetor\n");
        exit(1);
    }
    else if(arvore[q].usado){
        printf("Insercao incorreta\n");
        exit(1);
    }
    else {
        arvore[q].valor = number;
        arvore[q].usado = true;
    }
}

int Insere_Bin(struct Arvore *arvore, int num){
    int p, q;
    p = q = 0;
    if(!arvore[0].usado){
        cria_arvore(arvore, num);
        return SUCESSO;
    }
    while(q < NUM_NODES && arvore[q].usado && num != arvore[p].valor){
        p = q;
        if(num < arvore[p].valor){
            q = ESQ(p);
        }
        else {
            q = DIR(p);
        }
    }
    if(num == arvore[p].valor){
        printf("valor %d já existe\n", num);
        return FALHA;
    }
    else if(num < arvore[p].valor){
        insere_esquerda(arvore, p, num);
        printf("Inserido na esquerda de %d\n", arvore[p].valor);
        return SUCESSO;
    }
    else {
        insere_direita(arvore, p, num);
        printf("Inserido na direita de %d\n", arvore[p].valor);
        return SUCESSO;
    }
}

int Remove_Bin(struct Arvore *arvore, int num){
    int p, q;
    p = q = 0;
    if(!arvore[0].usado){
        printf("Arvore vazia\n");
        return FALHA;
    }
    while(q < NUM_NODES && arvore[q].usado && num != arvore[p].valor){
        p = q;
        if(num < arvore[p].valor){
            q = ESQ(p);
        }
        else {
            q = DIR(p);
        }
    }
    if(num == arvore[p].valor){
        if (!arvore[ESQ(p)].usado && !arvore[DIR(p)].usado) {
            arvore[p].usado = false;
            return SUCESSO;
        }
        else if (!arvore[ESQ(p)].usado) {
            arvore[p].valor = arvore[DIR(p)].valor;
            arvore[DIR(p)].usado = false;
            return SUCESSO;
        }
        else if (!arvore[DIR(p)].usado) {
            arvore[p].valor = arvore[ESQ(p)].valor;
            arvore[ESQ(p)].usado = false;
            return SUCESSO;
        }
        else {
            int r = DIR(p);
            while (arvore[ESQ(r)].usado) {
                r = ESQ(r);
            }
            arvore[p].valor = arvore[r].valor;
            arvore[r].usado = false;
            return SUCESSO;
        }
    }
    else {
        printf("Elemento %d não encontrado\n", num);
        return FALHA;
    }
}

void Pre_Ordem(struct Arvore *arvore, int n){
    if(arvore[n].usado){
        printf("%d ", arvore[n].valor);
        Pre_Ordem(arvore, ESQ(n));
        Pre_Ordem(arvore, DIR(n));
    }
}

void In_Ordem(struct Arvore *arvore, int n){
    if(arvore[n].usado){
        In_Ordem(arvore, ESQ(n));
        printf("%d ", arvore[n].valor);
        In_Ordem(arvore, DIR(n));
    }
}

void Pos_Ordem(struct Arvore *arvore, int n){
    if(arvore[n].usado){
        Pos_Ordem(arvore, ESQ(n));
        Pos_Ordem(arvore, DIR(n));
        printf("%d ", arvore[n].valor);
    }
}

int main(){

    int opcao = 0;
    char numeros[BUFFER_SIZE];

    /* Criação da Árvore */
    struct Arvore arvore[NUM_NODES];

    while(1){
        printf("Digite 1 para inserir um valor na árvore ou 2 para remover um valor da árvore: ");
        scanf("%d", &opcao);
        while (getchar() != '\n'); // Limpa o buffer do teclado

        if(opcao == INSERIR){
            printf("Digite um valor para inserir na árvore: ");
            scanf("%[0-9-+, ]", numeros);
            char *num = strtok(numeros,", \n");
            while(num != NULL){
                int converted = atoi(num);
                Insere_Bin(arvore, converted);
                num = strtok(NULL,", \n");
            }
        }
        else if(opcao == REMOVER){
            printf("Digite um valor para remover da árvore: ");
            scanf("%[0-9-+, ]", numeros);
            char *num = strtok(numeros,", \n");
            while(num != NULL){
                int converted = atoi(num);
                Remove_Bin(arvore, converted);
                num = strtok(NULL,", \n");
            }
        }
        else{
            printf("Opção inválida\n");
            return 1;
        }

        print_line();
        printf("Pre Ordem:\n");
        Pre_Ordem(arvore, INDICE_RAIZ);
        print_line();

        printf("In Ordem:\n");
        In_Ordem(arvore,  INDICE_RAIZ);
        print_line();

        printf("Pos Ordem:\n");
        Pos_Ordem(arvore, INDICE_RAIZ);
        print_line();
    }

    return 0;
}
