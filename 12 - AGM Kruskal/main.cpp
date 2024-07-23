//
// Created by Gabriel Fonte on 09/07/24.
//

#include <iostream>
#include <fstream>
#include <list>
#include <sstream>
#include <string>
#include <algorithm>
#include "KRUSKAL.hpp"

#define READ_FROM_FILE      1
#define MANUAL_INSERTION    2

int main() {
    std::string vertices;
    std::list <std::string> edges;


    std::cout << "------ KRUSKAL Activity -----" << std::endl;
    std::cout << "Enter 1 to read from file or 2 to enter manually: ";
    int option;
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    KRUSKAL<std::string> kruskal;
    std::string root;

    if (option == MANUAL_INSERTION){
        std::cout << "Enter the vertices list separated by commas: ";
        std::cin >> vertices;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter the root vertex: ";
        std::cin >> root;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout
        << "\nEnter the edges list separated by commas in the following format (vi, w, vf). \n"
           "To stop inserting vertices just enter an empty value: \n"
           "Note: this is an undirected graph, so the edge (vi, vf) is the same as (vf, vi). \n";

        while (true) {
            std::string edge;
            std::getline(std::cin, edge);
            if (edge.empty()) {
                std::cout << "End of edges list." << std::endl;
                break;
            }
            std::cout << "Edge: " << edge << std::endl;
            edges.push_back(edge);
        }
    }

    if (option == READ_FROM_FILE){
        std::cout << "Enter the file name: ";
        std::string file_name;
        std::cin >> file_name;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::ifstream file(file_name);
        if(file.is_open()){
            std::getline(file, root);
            std::getline(file, vertices);
            while(!file.eof()){
                std::string edge;
                std::getline(file, edge);
                edges.push_back(edge);
            }
            file.close();
        }
    }

    std::stringstream v_stream(vertices);
    while(v_stream.good()) {
        std::string v;
        getline(v_stream, v, ',');
        kruskal.addVertex(v);
        std::cout << "Vertex " << v << " added." << std::endl;
    }

    for(auto e : edges){
        std::string v_origin, v_destiny, weight;
        std::stringstream edge_stream(e);
        getline(edge_stream, v_origin, ',');
        getline(edge_stream, weight, ',');
        getline(edge_stream, v_destiny, ',');
        v_origin.erase(std::remove(v_origin.begin(), v_origin.end(), '('), v_origin.end());
        v_destiny.erase(std::remove(v_destiny.begin(), v_destiny.end(), ')'), v_destiny.end());
        weight.erase(std::remove(weight.begin(), weight.end(), 'p'), weight.end());
        std::cout << "Origin: " << v_origin << " Destiny: " << v_destiny << " Weight: " << weight << std::endl;
        kruskal.addEdge(v_origin, v_destiny, std::stoi(weight));
        std::cout << "Edge (" << v_origin << ", " << v_destiny << ") with weight " << weight << " added." << std::endl;
    }

    std::cout << "KRUSKAL Tree:" << std::endl;
    kruskal.generate_tree(root);

    return 0;
}
