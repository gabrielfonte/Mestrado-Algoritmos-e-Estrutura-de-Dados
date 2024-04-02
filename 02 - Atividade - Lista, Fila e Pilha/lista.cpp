//
// Created by gabrielfonte on 01/04/24.
//

#include "lista.hpp"

int lista::_Insere(aluno_t *lista, int num, posicao_e posicao){
    int pos = 0;

    if(lista != nullptr) {

        /* Cria um ponteiro para percorrer a lista */
        struct Aluno *p_lista = lista;


        if(posicao != BUSCA_INICIO) {
            /* Percorre a lista até obter o último elemento */
            while(p_lista->proximo != nullptr){
                if(posicao == BUSCA_ORDENACAO){
                    if(num <= p_lista->proximo->valor){
                        break;
                    }
                }
                p_lista = p_lista->proximo;
                pos++;
                /* Caso a posição seja encontrada, interrompe o laço */
                if(pos == posicao){
                    break;
                }
                /* Caso o valor seja encontrado */
                if(posicao == BUSCA_VALOR){
                    break;
                }
            }
        }

        /* Guarda o endereço inserido anteriormente em uma variável temporária */
        aluno_t *temp_aluno = p_lista->proximo;

        /* Aloca memória para a inserção do novo elemento */
        p_lista->proximo = (aluno_t*) malloc(sizeof(struct Aluno));

        /* Insere o novo elemento */
        p_lista->proximo->valor = num;

        /* Atribui o valor da variável temporária no próximo do próximo, ligando a lista novamente */
        p_lista->proximo->proximo = temp_aluno;

        return SUCESSO;
    }

    return FALHA;
}

int lista::_Remove(aluno_t *lista, int num, posicao_e posicao){
    int pos = 0;

    if(lista != nullptr){
        /* Cria um ponteiro para percorrer a lista */
        struct Aluno *p_lista = lista;

        /* Verificação se existe um elemento na lista */
        if(p_lista->proximo != nullptr){
            /* Percorre a lista até obter o valor especificado ou a lista terminar */

            if(posicao != BUSCA_INICIO){
                while(p_lista->proximo->proximo != nullptr && p_lista->proximo->valor != num){
                    p_lista = p_lista->proximo;
                    pos++;
                    /* Caso a posição seja encontrada, interrompe o laço */
                    if(pos == posicao){
                        break;
                    }
                    if(posicao == BUSCA_VALOR){
                        if(p_lista->valor == num){
                            break;
                        }
                    }
                }
            }

            /* Remove o elemento da lista, caso este seja o valor especificado */
            std::cout << "Removendo " << p_lista->proximo->valor << " da estrutura" << std::endl;
            /* O elemento a ser removido é o próximo da lista */
            struct Aluno *p_remover = p_lista->proximo;
            /* Este elemento deve ser substituído pelo ponteiro do próximo, de forma a ligar a lista novamente */
            p_lista->proximo = p_remover->proximo;
            /* Desaloca a memória do elemento removido */
            free(p_remover);

            return SUCESSO;
        }
    }

    return FALHA;
}

void lista::_Imprime(aluno_t *lista){
    /* Verifica se a lista é um endereço válido */
    if(lista != nullptr){
        /* Cria um ponteiro para percorrer a lista */
        struct Aluno *p_lista = lista->proximo;

        /* Cria um índice para mostrar a posicao de cada aluno na lista */
        int indice = 0;

        /* Percorre a lista até obter o último elemento */
        while(p_lista != nullptr){
            std::cout << "Aluno[" << indice << "]: " << p_lista->valor << std::endl;
            indice++;
            p_lista = p_lista->proximo;
        }
    }
}

int lista::Insere(int num){
    return this->_Insere(this->lista__, num, BUSCA_ORDENACAO);
}

int lista::Remove(int num){
    return this->_Remove(this->lista__, num, BUSCA_VALOR);
}

void lista::Imprime(){
    std::cout << "Lista de alunos" << std::endl;
    this->_Imprime(this->lista__);
}