//
// Created by Gabriel Fonte on 03/06/24.
//

#ifndef INC_08_ATIVIDADE_DE_HASH_LISTGENERATOR_HPP
#define INC_08_ATIVIDADE_DE_HASH_LISTGENERATOR_HPP

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#define DATA_SOURCE "data/random_list.txt"

class ListGenerator {
    public:
    std::vector<std::string> list;
    std::vector<std::string> *create_random_list(int size);
    std::vector<std::string> *create_list_from_file(std::string file_name);
    void print_list();
};


#endif //INC_08_ATIVIDADE_DE_HASH_LISTGENERATOR_HPP
