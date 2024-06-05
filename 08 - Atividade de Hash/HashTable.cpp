//
// Created by Gabriel Fonte on 03/06/24.
//

#include "HashTable.hpp"

#define ASCII_OFFSET   97
#define NUMBERS_OFFSET 48

/* Função de hash simples, utilizando apenas o módulo do tamanho da tabela e a posição da letra do alfabeto */
int hash_simple_function(std::string key, unsigned int &hash) {
    if(key.size() > 0){
        hash = (key.at(0)-ASCII_OFFSET) % HASH_PRIME;
        return HASH_SUCCESS;
    }

    return HASH_ERROR;
}

/* Função de hash compatível com a vista em sala, utilizando divisão de primos com
 * hashing perfeito de base 26 e primo igual a 31 */
int hash_perfect_function(std::string key, unsigned int &hash) {
    if(key.size() > 0){
        for(int i=0; i<(key.size()-1); i++){
            hash += ((unsigned int)key.at(i) - ASCII_OFFSET) * HASH_BASE;
        }
        hash += ((unsigned int)key.at(key.size()-1) - ASCII_OFFSET);
        hash = hash % HASH_PRIME;
        return HASH_SUCCESS;
    }

    return HASH_ERROR;
}

/* Função de hash utilizando seleção de dígitos */
int hash_selection_function(std::string key, unsigned int &hash) {
    if(key.size() > 0){
        hash = 0;
        std::string unselect;
        //std::cout << "KEY: " << key << std::endl;
        for(int i=0; i<key.size(); i++){
            unsigned int key_value = (unsigned int) key.at(i) - ASCII_OFFSET;
            unselect.push_back(key_value/10 + NUMBERS_OFFSET);
            unselect.push_back(key_value%10 + NUMBERS_OFFSET);
        }
        for(int j=1; j<unselect.size(); j+=2){
            hash *= 10;
            hash += ((unsigned int) unselect.at(j) - NUMBERS_OFFSET);
        }
        //std::cout << "UNSELECT: " << unselect << std::endl;
        //std::cout << "HASH: " << hash << std::endl;
        hash = hash % HASH_PRIME;
        return HASH_SUCCESS;
    }

    return HASH_ERROR;
}

/* Função de hash utilizando o meio quadrado e seleção */
int hash_middle_square_function(std::string key, unsigned int &hash) {
    if (key.size() > 0) {
        hash = 0;
        unsigned int unselect;
        std::string unselect_string;

        //std::cout << "KEY: " << key << std::endl;
        for(int i=0; i<key.size(); i++){
            unsigned int key_value = (unsigned int) key.at(i) - ASCII_OFFSET;
            unselect *= 10;
            unselect += key_value/10;
            unselect *= 10;
            unselect += key_value%10;
        }
        //std::cout << "UNSELECT: " << unselect << std::endl;

        unselect = unselect * unselect;
        unselect_string = std::to_string(unselect);

        for(int j=1; j<unselect_string.size(); j+=2){
            hash *= 10;
            hash += ((unsigned int) unselect_string.at(j) - NUMBERS_OFFSET);
        }

        //std::cout << "UNSELECT SQUARE: " << unselect << std::endl;
        //std::cout << "HASH: " << hash << std::endl;

        hash = hash % HASH_PRIME;
        return HASH_SUCCESS;
    }

    return HASH_ERROR;
}

/* Construtor da classe HashTable */
HashTable::HashTable(unsigned int size, HashFunction HASH_FUNCTION){
    this->size = size;
    table = new std::list<std::pair<std::string, int>>[size];
    switch (HASH_FUNCTION) {
        case SIMPLE_HASH:
            hash_function = &hash_simple_function;
            break;
        case PERFECT_HASH:
            hash_function = &hash_perfect_function;
            break;
        case SELECTION_HASH:
            hash_function = &hash_selection_function;
            break;
        case MIDDLE_SQUARE_HASH:
            hash_function = &hash_middle_square_function;
            break;
    }
}

/* Destrutor da classe HashTable */
HashTable::~HashTable() {
    delete[] table;
}

/* Método de inserção de um elemento na tabela hash */
void HashTable::insert(std::string key, int value) {
    unsigned int hash = 0;
    int hash_result = hash_function(key, hash);

    if(hash_result == HASH_ERROR){
        std::cout << "Error hashing key" << std::endl;
        return;
    }

    if(table[hash].empty()){
        table[hash].push_back(std::make_pair(key, value));
    }
    else{
        //std::cout << "Collision detected" << std::endl;
        collisions++;
        table[hash].push_back(std::make_pair(key, value));
    }
}

/* Método de remoção de um elemento na tabela hash */
void HashTable::remove(std::string key) {
    unsigned int hash = 0;
    int hash_result = hash_function(key, hash);

    if(hash_result == HASH_ERROR){
        std::cout << "Error hashing key" << std::endl;
        return;
    }

    for (auto it = table[hash].begin(); it != table[hash].end(); ++it) {
        if (it->first == key) {
            table[hash].erase(it);
            break;
        }
    }
}

/* Método de busca de um elemento na tabela hash */
bool HashTable::search(std::string key) {
    unsigned int hash = 0;
    int hash_result = hash_function(key, hash);

    if(hash_result == HASH_ERROR){
        std::cout << "Error hashing key" << std::endl;
        return false;
    }

    for (auto it = table[hash].begin(); it != table[hash].end(); ++it) {
        if (it->first == key) {
            return true;
        }
    }

    return false;
}

/* Método de impressão da tabela hash */
void HashTable::print() {
    for(int i=0; i<size; i++){
        std::cout << i << ": [";
        for(auto &it : table[i]){
            std::cout << it.first << ": " << it.second << "; ";
        }
        std::cout << "]" << std::endl;
    }
}