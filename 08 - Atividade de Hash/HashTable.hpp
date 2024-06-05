//
// Created by Gabriel Fonte on 03/06/24.
//

#ifndef INC_08_ATIVIDADE_DE_HASH_HASHTABLE_HPP
#define INC_08_ATIVIDADE_DE_HASH_HASHTABLE_HPP

#include <string>
#include <iostream>
#include <list>

#define HASH_SUCCESS           0
#define HASH_ERROR             1

#define HASH_BASE              26
#define HASH_PRIME             499

enum HashFunction {
    SIMPLE_HASH,
    PERFECT_HASH,
    SELECTION_HASH,
    MIDDLE_SQUARE_HASH
};

class HashTable {
private:
    int (*hash_function)(std::string, unsigned int&);
    std::list<std::pair<std::string, int>> *table;

public:
    unsigned int size;
    unsigned int collisions = 0;

    HashTable(unsigned int size, HashFunction HASH_FUNCTION=SIMPLE_HASH);
    ~HashTable();

    void insert(std::string key, int value);
    void remove(std::string key);
    bool search(std::string key);
    void print();
};


#endif //INC_08_ATIVIDADE_DE_HASH_HASHTABLE_HPP
