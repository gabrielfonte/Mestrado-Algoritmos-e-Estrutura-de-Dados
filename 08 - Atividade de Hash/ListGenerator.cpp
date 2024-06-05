//
// Created by Gabriel Fonte on 03/06/24.
//

#include "ListGenerator.hpp"

#include <random> // for std::random_device and std::mt19937

std::string filter_string(const std::string& input) {
    std::string output;
    for (char c : input) {
        if (c >= 97 && c <= 122) { // ASCII printable characters
            output += c;
        }
        else if(c >= 65 && c <= 90){ // ASCII uppercase characters
            output += c + 32; // convert to lowercase
        }
    }
    return output;
}

std::vector<std::string> *ListGenerator::create_random_list(int size) {
    std::ifstream file(DATA_SOURCE);
    std::string line;
    std::vector<std::string> all_lines;
    std::vector<std::string> random_lines;

    if(file.is_open()){
        //std::cout << "File opened successfully" << std::endl;
        while(getline(file, line)){
            all_lines.push_back(filter_string(line));
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, all_lines.size() - 1);

        for(int i = 0; i < size; i++){
            int random_index = dis(gen);
            random_lines.push_back(all_lines[random_index]);
        }
    }

    list = random_lines;

    std::cout << "Created list with " << list.size() << " elements" << std::endl;

    return &list;
}

std::vector<std::string> *ListGenerator::create_list_from_file(std::string file_name) {
    std::ifstream file(file_name);
    std::string line;
    std::vector<std::string> all_lines;

    if(file.is_open()){
        //std::cout << "File opened successfully" << std::endl;
        while(getline(file, line)){
            all_lines.push_back(filter_string(line));
        }
    }

    list = all_lines;

    std::cout << "Created list with " << list.size() << " elements" << std::endl;

    return &list;
}

void ListGenerator::print_list() {
    for(auto &i : list){
        std::cout << i << std::endl;
    }
}