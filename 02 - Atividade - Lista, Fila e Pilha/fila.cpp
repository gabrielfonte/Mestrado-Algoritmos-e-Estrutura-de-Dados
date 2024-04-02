//
// Created by gabrielfonte on 01/04/24.
//

#include "fila.hpp"

int fila::Insere(int num) {
    return this->_Insere(this->lista__, num, BUSCA_FIM);
}

int fila::Remove(int num) {
    return this->_Remove(this->lista__, num, BUSCA_INICIO);
}