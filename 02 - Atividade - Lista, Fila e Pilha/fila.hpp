//
// Created by gabrielfonte on 01/04/24.
//

#ifndef MESTRADO_ALGORITMOS_E_ESTRUTURA_DE_DADOS_FILA_HPP
#define MESTRADO_ALGORITMOS_E_ESTRUTURA_DE_DADOS_FILA_HPP

#include <lista.hpp>

class fila: public lista {
    public:
        int Insere(int num) override;
        int Remove(int num = DEFAULT) override;
};

#endif //MESTRADO_ALGORITMOS_E_ESTRUTURA_DE_DADOS_FILA_HPP
