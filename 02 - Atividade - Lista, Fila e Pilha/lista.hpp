//
// Created by gabrielfonte on 01/04/24.
//

#ifndef MESTRADO_ALGORITMOS_E_ESTRUTURA_DE_DADOS_LISTA_HPP
#define MESTRADO_ALGORITMOS_E_ESTRUTURA_DE_DADOS_LISTA_HPP

#include <tipos.hpp>
#include <cstdlib>
#include <cstdio>

class lista {
    protected:
    aluno_t *lista__;
    int _Insere(aluno_t *lista, int num, posicao_e posicao);
    int _Remove(aluno_t *lista, int num, posicao_e posicao);
    void _Imprime(aluno_t *lista);
    void _Ordena(aluno_t *lista);

    public:
    virtual int Insere(int num);
    virtual int Remove(int num);
    void Imprime();

    public:
    lista(){
        printf("Lista()\n");
        lista__ = (aluno_t*) malloc(sizeof(aluno_t));
        lista__->valor = 0;
        lista__->proximo = nullptr;
    }

    ~lista(){
        while(this->_Remove(this->lista__, 0, BUSCA_INICIO) == SUCESSO);
        free(lista__);
    }
};


#endif //MESTRADO_ALGORITMOS_E_ESTRUTURA_DE_DADOS_LISTA_HPP
