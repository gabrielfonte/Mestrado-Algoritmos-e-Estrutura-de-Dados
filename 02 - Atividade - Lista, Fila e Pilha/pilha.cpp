//
// Created by gabrielfonte on 01/04/24.
//

#include "pilha.hpp"

int pilha::Insere(int num) {
    return this->_Insere(this->lista__, num, BUSCA_FIM);
}

int pilha::Remove() {
    return this->_Remove(this->lista__, 0, BUSCA_INICIO);
}