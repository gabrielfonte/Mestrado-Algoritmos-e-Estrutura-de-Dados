//
// Created by gabrielfonte on 01/04/24.
//

#ifndef MESTRADO_ALGORITMOS_E_ESTRUTURA_DE_DADOS_TIPOS_HPP
#define MESTRADO_ALGORITMOS_E_ESTRUTURA_DE_DADOS_TIPOS_HPP

#define DEFAULT 0x00

typedef enum {
    INSERIR = 1,
    REMOVER = 2,
} opcoes_e;

typedef enum {
    SUCESSO,
    FALHA
} codigos_erro_e;

typedef enum {
    BUSCA_VALOR = -4,
    BUSCA_INICIO = -3,
    BUSCA_FIM = -2,
    BUSCA_ORDENACAO = -1,
} posicao_e;

typedef struct Aluno {
    int valor;
    struct Aluno *proximo;
} aluno_t;

#endif //MESTRADO_ALGORITMOS_E_ESTRUTURA_DE_DADOS_TIPOS_HPP
