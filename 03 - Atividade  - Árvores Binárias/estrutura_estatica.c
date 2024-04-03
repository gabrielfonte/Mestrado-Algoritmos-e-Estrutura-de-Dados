//
// Created by Gabriel Fonte on 01/04/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512
#define NUM_NODES   500

#define print_line() printf("-------------------------------------------------\n")

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
    int usado;
};

void cria_arvore(struct Arvore *arvore, int number){
    int p;
    arvore[0].valor = number;
    arvore[0].usado = 1;
    for(p = 1; p < NUM_NODES; p++){
        arvore[p].usado = 0;
    }
}

void setleft(struct Arvore *arvore, int p, int number){
    int q;
    q = 2 * p + 1;
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
        arvore[q].usado = 1;
    }
}

void setright(struct Arvore *arvore, int p, int number){
    int q;
    q = 2 * p + 2;
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
        arvore[q].usado = 1;
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
            q = 2 * p + 1;
        }
        else {
            q = 2 * p + 2;
        }
    }
    if(num == arvore[p].valor){
        printf(" %d esta repetido\n", num);
        return FALHA;
    }
    else if(num < arvore[p].valor){
        setleft(arvore, p, num);
        return SUCESSO;
    }
    else {
        setright(arvore, p, num);
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
            q = 2 * p + 1;
        }
        else {
            q = 2 * p + 2;
        }
    }
    if(num == arvore[p].valor){
        arvore[p].usado = 0;
        return SUCESSO;
    }
    else {
        printf("Elemento %d não encontrado\n", num);
        return FALHA;
    }
}

void Imprime_Arv(struct Arvore *arvore){
    int p;
    for(p = 0; p < NUM_NODES; p++){
        if(arvore[p].usado){
            printf("%d ", arvore[p].valor);
        }
    }
    printf("\n");
}

int main(){

    int opcao = 0;
    char numeros[BUFFER_SIZE];

    /* Criação da Árvore */
    struct Arvore arvore[NUM_NODES];

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
        
        Imprime_Arv(arvore);
    }

    return 0;
}
