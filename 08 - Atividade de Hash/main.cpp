#include <iostream>
#include "HashTable.hpp"

int main(){
    int hash = 0;
    std::string key = "gabriel";
    hash_function(key, hash);
    std::cout << "Hash: " << hash << std::endl;
    return 0;
}
