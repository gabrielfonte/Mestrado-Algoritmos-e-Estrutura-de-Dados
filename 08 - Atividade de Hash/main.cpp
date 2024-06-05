#include <iostream>
#include "HashTable.hpp"
#include "ListGenerator.hpp"

#define TABLE_SIZE HASH_PRIME

#define PRINT_HASH_TABLE 1 //set to 1 to print hash table

void create_random_list_30_elements(){
    std::cout << "------ 30 RANDOM ELEMENTS TEST -------" << std::endl;
    std::cout << "Creating random list with size 30 and hash table size " << TABLE_SIZE << std::endl;

    ListGenerator list_generator;

    HashTable hash_table_simple(TABLE_SIZE, SIMPLE_HASH);
    HashTable hash_table_perfect(TABLE_SIZE, PERFECT_HASH);
    HashTable hash_table_selection(TABLE_SIZE, SELECTION_HASH);
    HashTable hash_table_middle_square(TABLE_SIZE, MIDDLE_SQUARE_HASH);

    list_generator.create_random_list(30);

    for(int i = 0; i < list_generator.list.size(); i++){
        int random_age = rand() % 25 + 20;
        hash_table_simple.insert(list_generator.list[i], random_age);
        hash_table_perfect.insert(list_generator.list[i], random_age);
        hash_table_selection.insert(list_generator.list[i], random_age);
        hash_table_middle_square.insert(list_generator.list[i], random_age);
    }

#if PRINT_HASH_TABLE
    hash_table_simple.print();
    hash_table_middle_square.print();
    hash_table_perfect.print();
    hash_table_selection.print();
#endif

    std::cout << "Collisions Simple Hash: " << hash_table_simple.collisions << std::endl;
    std::cout << "Collisions Perfect Hash: " << hash_table_perfect.collisions << std::endl;
    std::cout << "Collisions Selection Hash: " << hash_table_selection.collisions << std::endl;
    std::cout << "Collisions Middle Square Hash: " << hash_table_middle_square.collisions << std::endl;
}

void create_random_list_100_elements(){
    std::cout << "------ 100 RANDOM ELEMENTS TEST -------" << std::endl;
    std::cout << "Creating random list with size 100 and hash table size " << TABLE_SIZE << std::endl;

    ListGenerator list_generator;

    HashTable hash_table_simple(TABLE_SIZE, SIMPLE_HASH);
    HashTable hash_table_perfect(TABLE_SIZE, PERFECT_HASH);
    HashTable hash_table_selection(TABLE_SIZE, SELECTION_HASH);
    HashTable hash_table_middle_square(TABLE_SIZE, MIDDLE_SQUARE_HASH);

    list_generator.create_random_list(100);

    for(int i = 0; i < list_generator.list.size(); i++){
        int random_age = rand() % 25 + 20;
        hash_table_simple.insert(list_generator.list[i], random_age);
        hash_table_perfect.insert(list_generator.list[i], random_age);
        hash_table_selection.insert(list_generator.list[i], random_age);
        hash_table_middle_square.insert(list_generator.list[i], random_age);
    }

#if PRINT_HASH_TABLE
    hash_table_simple.print();
    hash_table_middle_square.print();
    hash_table_perfect.print();
    hash_table_selection.print();
#endif

    std::cout << "Collisions Simple Hash: " << hash_table_simple.collisions << std::endl;
    std::cout << "Collisions Perfect Hash: " << hash_table_perfect.collisions << std::endl;
    std::cout << "Collisions Selection Hash: " << hash_table_selection.collisions << std::endl;
    std::cout << "Collisions Middle Square Hash: " << hash_table_middle_square.collisions << std::endl;
}

void create_random_list_500_elements(){
    std::cout << "------ 500 RANDOM ELEMENTS TEST -------" << std::endl;
    std::cout << "Creating random list with size 500 and hash table size " << TABLE_SIZE << std::endl;

    ListGenerator list_generator;

    HashTable hash_table_simple(TABLE_SIZE, SIMPLE_HASH);
    HashTable hash_table_perfect(TABLE_SIZE, PERFECT_HASH);
    HashTable hash_table_selection(TABLE_SIZE, SELECTION_HASH);
    HashTable hash_table_middle_square(TABLE_SIZE, MIDDLE_SQUARE_HASH);

    list_generator.create_random_list(500);

    for(int i = 0; i < list_generator.list.size(); i++){
        int random_age = rand() % 25 + 20;
        hash_table_simple.insert(list_generator.list[i], random_age);
        hash_table_perfect.insert(list_generator.list[i], random_age);
        hash_table_selection.insert(list_generator.list[i], random_age);
        hash_table_middle_square.insert(list_generator.list[i], random_age);
    }

#if PRINT_HASH_TABLE
    hash_table_simple.print();
    hash_table_middle_square.print();
    hash_table_perfect.print();
    hash_table_selection.print();
#endif

    std::cout << "Collisions Simple Hash: " << hash_table_simple.collisions << std::endl;
    std::cout << "Collisions Perfect Hash: " << hash_table_perfect.collisions << std::endl;
    std::cout << "Collisions Selection Hash: " << hash_table_selection.collisions << std::endl;
    std::cout << "Collisions Middle Square Hash: " << hash_table_middle_square.collisions << std::endl;
}

void create_list_30_elements(){
    std::cout << "------ 30 ELEMENTS TEST -------" << std::endl;
    std::cout << "Creating list with size 30 and hash table size " << TABLE_SIZE << std::endl;

    ListGenerator list_generator;
    HashTable hash_table_simple(TABLE_SIZE, SIMPLE_HASH);
    HashTable hash_table_perfect(TABLE_SIZE, PERFECT_HASH);
    HashTable hash_table_selection(TABLE_SIZE, SELECTION_HASH);
    HashTable hash_table_middle_square(TABLE_SIZE, MIDDLE_SQUARE_HASH);

    list_generator.create_list_from_file("data/list_30.txt");

    for(int i = 0; i < list_generator.list.size(); i++){
        int random_age = rand() % 25 + 20;
        hash_table_simple.insert(list_generator.list[i], random_age);
        hash_table_perfect.insert(list_generator.list[i], random_age);
        hash_table_selection.insert(list_generator.list[i], random_age);
        hash_table_middle_square.insert(list_generator.list[i], random_age);
    }

#if PRINT_HASH_TABLE
    hash_table_simple.print();
    hash_table_middle_square.print();
    hash_table_perfect.print();
    hash_table_selection.print();
#endif

    std::cout << "Collisions Simple Hash: " << hash_table_simple.collisions << std::endl;
    std::cout << "Collisions Perfect Hash: " << hash_table_perfect.collisions << std::endl;
    std::cout << "Collisions Selection Hash: " << hash_table_selection.collisions << std::endl;
    std::cout << "Collisions Middle Square Hash: " << hash_table_middle_square.collisions << std::endl;
}

void create_list_100_elements(){
    std::cout << "------ 100 ELEMENTS TEST -------" << std::endl;
    std::cout << "Creating list with size 100 and hash table size " << TABLE_SIZE << std::endl;

    ListGenerator list_generator;
    HashTable hash_table_simple(TABLE_SIZE, SIMPLE_HASH);
    HashTable hash_table_perfect(TABLE_SIZE, PERFECT_HASH);
    HashTable hash_table_selection(TABLE_SIZE, SELECTION_HASH);
    HashTable hash_table_middle_square(TABLE_SIZE, MIDDLE_SQUARE_HASH);

    list_generator.create_list_from_file("data/list_100.txt");

    for(int i = 0; i < list_generator.list.size(); i++){
        int random_age = rand() % 25 + 20;
        hash_table_simple.insert(list_generator.list[i], random_age);
        hash_table_perfect.insert(list_generator.list[i], random_age);
        hash_table_selection.insert(list_generator.list[i], random_age);
        hash_table_middle_square.insert(list_generator.list[i], random_age);
    }

#if PRINT_HASH_TABLE
    hash_table_simple.print();
    hash_table_middle_square.print();
    hash_table_perfect.print();
    hash_table_selection.print();
#endif

    std::cout << "Collisions Simple Hash: " << hash_table_simple.collisions << std::endl;
    std::cout << "Collisions Perfect Hash: " << hash_table_perfect.collisions << std::endl;
    std::cout << "Collisions Selection Hash: " << hash_table_selection.collisions << std::endl;
    std::cout << "Collisions Middle Square Hash: " << hash_table_middle_square.collisions << std::endl;
}

void create_list_500_elements(){
    std::cout << "------ 500 ELEMENTS TEST -------" << std::endl;
    std::cout << "Creating list with size 500 and hash table size " << TABLE_SIZE << std::endl;

    ListGenerator list_generator;
    HashTable hash_table_simple(TABLE_SIZE, SIMPLE_HASH);
    HashTable hash_table_perfect(TABLE_SIZE, PERFECT_HASH);
    HashTable hash_table_selection(TABLE_SIZE, SELECTION_HASH);
    HashTable hash_table_middle_square(TABLE_SIZE, MIDDLE_SQUARE_HASH);

    list_generator.create_list_from_file("data/list_500.txt");

    for(int i = 0; i < list_generator.list.size(); i++){
        int random_age = rand() % 25 + 20;
        hash_table_simple.insert(list_generator.list[i], random_age);
        hash_table_perfect.insert(list_generator.list[i], random_age);
        hash_table_selection.insert(list_generator.list[i], random_age);
        hash_table_middle_square.insert(list_generator.list[i], random_age);
    }

#if PRINT_HASH_TABLE
    hash_table_simple.print();
    hash_table_middle_square.print();
    hash_table_perfect.print();
    hash_table_selection.print();
#endif

    std::cout << "Collisions Simple Hash: " << hash_table_simple.collisions << std::endl;
    std::cout << "Collisions Perfect Hash: " << hash_table_perfect.collisions << std::endl;
    std::cout << "Collisions Selection Hash: " << hash_table_selection.collisions << std::endl;
    std::cout << "Collisions Middle Square Hash: " << hash_table_middle_square.collisions << std::endl;
}

int main(){

    /* Random Lists */
    create_random_list_30_elements();
    create_random_list_100_elements();
    create_random_list_500_elements();

    /* Predefined Lists */
    create_list_30_elements();
    create_list_100_elements();
    create_list_500_elements();

    return 0;
}
