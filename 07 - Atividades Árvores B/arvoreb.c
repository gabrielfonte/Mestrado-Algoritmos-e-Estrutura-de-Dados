#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define ORDEM       2
#define REGISTROS  (2 * ORDEM)

#define NIVEL_RAIZ  0

enum opcoes {
    INSERIR = 1,
    REMOVER = 2,
};

typedef struct NoArvoreB* NoArvoreB_ptr;

typedef struct NoArvoreB {
    int numero_chaves;
    int chaves[REGISTROS];
    NoArvoreB_ptr filhos[REGISTROS+1];
} NoArvoreB;

/* Inicializa a árvore com um valor nulo */
void InicializaArvoreB(NoArvoreB_ptr *ArvoreB) {
    *ArvoreB = NULL;
}

/* Busca o índice de inserção utilizando busca binária */
int BuscaIndiceArvoreB(struct NoArvoreB *p, int *valor){
    int e = -1, d = p->numero_chaves, m;
    while(e < d-1){
        m = (e+d)/2;
        if(p->chaves[m] < *valor){
            e = m;
        }
        else{
            d = m;
        }
    }
    return d;
}

/* Insere um valor na página */
void InsereNaPagina(NoArvoreB_ptr Ap, int valor, NoArvoreB_ptr ApDir) {
    int posicao = BuscaIndiceArvoreB(Ap, &valor);

    for(int i = Ap->numero_chaves; i >= posicao ; i--){
        Ap->chaves[i] = Ap->chaves[i-1];
        Ap->filhos[i+1] = Ap->filhos[i];
    }

    Ap->chaves[posicao] = valor;
    Ap->filhos[posicao+1] = ApDir;
    Ap->numero_chaves++;
}

bool InsereRecArvB(NoArvoreB_ptr Ap, NoArvoreB_ptr *ApRet, int *valor, bool *propagar) {
    int i, j;
    NoArvoreB_ptr ApTemp;

    if (Ap == NULL) {
        *propagar = true;
        (*ApRet) = NULL;
        return true;
    }

    i = BuscaIndiceArvoreB(Ap, valor);
    if (i < Ap->numero_chaves && *valor == Ap->chaves[i]) {
        printf(" Erro: valor já existe\n");
        *propagar = false;
        return false;
    }

    bool inseriu = InsereRecArvB(Ap->filhos[i], ApRet, valor, propagar);
    if (*propagar) {
        if (Ap->numero_chaves < REGISTROS) {
            InsereNaPagina(Ap, *valor, *ApRet);
            *propagar = false;
        } else {
            ApTemp = (NoArvoreB_ptr) malloc(sizeof(NoArvoreB));
            ApTemp->numero_chaves = 0;
            ApTemp->filhos[0] = NULL;
            if (i < ORDEM + 1) {
                InsereNaPagina(ApTemp, Ap->chaves[REGISTROS-1], Ap->filhos[REGISTROS]);
                Ap->numero_chaves--;
                InsereNaPagina(Ap, *valor, *ApRet);
            } else {
                InsereNaPagina(ApTemp, *valor, *ApRet);
            }
            for (j = ORDEM + 2; j <= REGISTROS; j++) {
                InsereNaPagina(ApTemp, Ap->chaves[j - 1], Ap->filhos[j]);
            }
            Ap->numero_chaves = ORDEM;
            ApTemp->filhos[0] = Ap->filhos[ORDEM+1];
            *valor = Ap->chaves[ORDEM];
            *ApRet = ApTemp;
        }
    }

    return inseriu;
}

/* Insere um valor na árvore */
void InsereArvB(NoArvoreB_ptr *Ap, int *valor) {
    bool propagar;
    NoArvoreB_ptr ApRet, ApTemp;

    InsereRecArvB(*Ap, &ApRet, valor, &propagar);
    if (propagar) {
        ApTemp = (NoArvoreB_ptr) malloc(sizeof(NoArvoreB));
        ApTemp->numero_chaves = 1;
        ApTemp->chaves[0] = *valor;
        ApTemp->filhos[1] = ApRet;
        ApTemp->filhos[0] = *Ap;
        *Ap = ApTemp;
    }
}

/* Reconstitui a árvore após a remoção de um valor */
void Reconstitui(NoArvoreB_ptr ApPag, NoArvoreB_ptr ApPai, int PosPai, bool *propagar) {
    NoArvoreB_ptr Aux;
    int DispAux, j;

    if (PosPai < ApPai->numero_chaves) {
        Aux = ApPai->filhos[PosPai+1];
        DispAux = (Aux->numero_chaves - ORDEM + 1) / 2;
        ApPag->chaves[ApPag->numero_chaves] = ApPai->chaves[PosPai];
        ApPag->filhos[ApPag->numero_chaves + 1] = Aux->filhos[0];  ApPag->numero_chaves++;
        if (DispAux > 0) {
            for (j = 1; j < DispAux; j++) {
                InsereNaPagina(ApPag, Aux->chaves[j-1], Aux->filhos[j]);
            }
            ApPai->chaves[PosPai] = Aux->chaves[DispAux-1];  Aux->numero_chaves -= DispAux;
            for (j = 0; j < Aux->numero_chaves; j++) Aux->chaves[j] = Aux->chaves[j + DispAux];
            for (j = 0; j <= Aux->numero_chaves; j++) Aux->filhos[j] = Aux->filhos[j + DispAux];
            *propagar = false;
        }
        else {
            for (j = 1; j <= ORDEM; j++) {
                InsereNaPagina(ApPag, Aux->chaves[j-1], Aux->filhos[j]);
            }
            free(Aux);
            for (j = PosPai + 1; j < ApPai->numero_chaves; j++) {
                ApPai->chaves[j-1] = ApPai->chaves[j];
                ApPai->filhos[j] = ApPai->filhos[j+1];
            }
            ApPai->numero_chaves--;
            if (ApPai->numero_chaves >= ORDEM) {
                *propagar = false;
            }
        }
    }
    else{
        Aux = ApPai->filhos[PosPai-1];
        DispAux = (Aux->numero_chaves - ORDEM + 1) / 2;
        for (j = ApPag->numero_chaves; j >= 1; j--){
            ApPag->chaves[j] = ApPag->chaves[j-1];
        }
        ApPag->chaves[0] = ApPai->chaves[PosPai-1];
        for (j = ApPag->numero_chaves; j >= 0; j--){
            ApPag->filhos[j+1] = ApPag->filhos[j];
        }
        ApPag->numero_chaves++;
        if (DispAux > 0){
            for (j = 1; j < DispAux; j++){
                InsereNaPagina(ApPag, Aux->chaves[Aux->numero_chaves - j],Aux->filhos[Aux->numero_chaves - j + 1]);
            }
            ApPag->filhos[0] = Aux->filhos[Aux->numero_chaves - DispAux + 1];
            ApPai->chaves[PosPai-1] = Aux->chaves[Aux->numero_chaves - DispAux];
            Aux->numero_chaves -= DispAux;  *propagar = false;
        }
        else{
            for (j = 1; j <= ORDEM; j++){
                InsereNaPagina(Aux, ApPag->chaves[j-1], ApPag->filhos[j]);
            }
            free(ApPag);
            ApPai->numero_chaves--;
            if (ApPai->numero_chaves >= ORDEM) {
                *propagar = false;
            }
        }
    }
}

/* Encontra o antecessor de um valor */
void Antecessor(NoArvoreB_ptr Ap, int Ind, NoArvoreB_ptr ApPai, bool *propagar) {
    if (ApPai->filhos[ApPai->numero_chaves] != NULL) {
        Antecessor(Ap, Ind, ApPai->filhos[ApPai->numero_chaves], propagar);
        if (*propagar){
            Reconstitui(ApPai->filhos[ApPai->numero_chaves], ApPai, (int)ApPai->numero_chaves, propagar);
        }
        return;
    }
    Ap->chaves[Ind-1] = ApPai->chaves[ApPai->numero_chaves - 1];
    ApPai->numero_chaves--;
    *propagar = (ApPai->numero_chaves < ORDEM);
}

/* Remove recursivamente um valor da árvore */
void RemoveRecArvoreB(NoArvoreB_ptr *Ap, int valor, bool *propagar) {
    int j, i = 1;
    NoArvoreB_ptr Pag;
    if (*Ap == NULL) {
        printf("Erro: registro nao esta na arvore\n");
        *propagar = false;
        return;
    }
    Pag = *Ap;
    while (i < Pag->numero_chaves && valor > Pag->chaves[i-1]) i++;
    if (valor == Pag->chaves[i-1]) {
        if (Pag->filhos[i-1] == NULL){
            Pag->numero_chaves--;
            *propagar = (Pag->numero_chaves < ORDEM);
            for (j = i; j <= Pag->numero_chaves; j++){
                Pag->chaves[j-1] = Pag->chaves[j];
                Pag->filhos[j] = Pag->filhos[j+1];
            }
            return;
        }
        Antecessor(*Ap, i, Pag->filhos[i-1], propagar);
        if (*propagar) {
            Reconstitui(Pag->filhos[i - 1], *Ap, i - 1, propagar);
        }
        return;
    }
    if (valor > Pag->chaves[i-1]){
        i++;
    }
    RemoveRecArvoreB(&Pag->filhos[i-1], valor, propagar);
    if (*propagar) {
        Reconstitui(Pag->filhos[i-1], *Ap, i - 1, propagar);
    }
}

/* Remove um valor da árvore */
void RemoveArvoreB(NoArvoreB_ptr *Ap, int valor) {
    bool propagar;
    NoArvoreB_ptr Aux;
    RemoveRecArvoreB(Ap, valor, &propagar);
    if (propagar && (*Ap)->numero_chaves == 0) {
        Aux = *Ap;
        *Ap = Aux->filhos[0];
        free(Aux);
    }
}

/* Imprime a árvore */
void ImprimeArvB(NoArvoreB_ptr p, int nivel) {
    int i;
    if (p == NULL) return;
    printf("Nivel %d : ", nivel);
    for (i = 0; i < p->numero_chaves; i++) {
        printf("%d ",(int)p->chaves[i]);
    }
    printf("\n");
    nivel++;
    for (i = 0; i <= p->numero_chaves; i++){
        ImprimeArvB(p->filhos[i], nivel);
    }
}

int main(int argc, char *argv[])
{
    int valor;
    int opcao = 0;
    bool opcao_valida = true;

    NoArvoreB_ptr arvore;
    InicializaArvoreB(&arvore);

    while(opcao_valida){
        printf("Digite 1 para inserir um valor na árvore ou 2 para remover um valor da árvore: ");
        scanf("%d", &opcao);
        while (getchar() != '\n'); // Limpa o buffer do teclado

        if(opcao == INSERIR){
            printf("Digite um valor para inserir na árvore: ");
            scanf("%d%*[^\n]", &valor);
            InsereArvB(&arvore, &valor);
        }
        else if(opcao == REMOVER){
            printf("Digite um valor para remover da árvore: ");
            scanf("%d%*[^\n]", &valor);
            RemoveArvoreB(&arvore, valor);
        }
        else{
            printf("Opção inválida\n");
            opcao_valida = false;
        }

        ImprimeArvB(arvore, NIVEL_RAIZ);
    }

    return 0;
}