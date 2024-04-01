//
// Created by gabrielfonte on 01/04/24.
//

#ifndef MESTRADO_ALGORITMOS_E_ESTRUTURA_DE_DADOS_PILHA_HPP
#define MESTRADO_ALGORITMOS_E_ESTRUTURA_DE_DADOS_PILHA_HPP

#include <lista.hpp>

class pilha: public lista {
    public:
    int Insere(int num) override;
    int Remove();
};


#endif //MESTRADO_ALGORITMOS_E_ESTRUTURA_DE_DADOS_PILHA_HPP
