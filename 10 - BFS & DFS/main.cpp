//
// Created by Gabriel Fonte on 09/07/24.
//

//Implemente a BFS e a DFS. A entrada deve ser um arquivo txt no seguinte formato:
//1) a primeira linha lista os vértices de G
//2) as linhas seguintes listam os pares de vértices que definem as arestas de G
//Exemplo:
//v0,v1,v2,v3
//(v0,v2)
//(v0,v1)
//(v1,v2)
//(v2,v3)
//Lembrando que para um grafo não orientado, devemos ter para to.do par (vi,vj) o par (vj,vi).
//Na ausência, o grafo será orientado.

//BFS(G);
///* G(V, A), |V| = n, |A| = m */
///* Estruturas: cor – cores; π –  ́arvore; d – distancia */
///* Cores: B (n ̃ao visitado), C (n ̃ao explorado) e P (explorado) */
//
//Para u = 1 ate n fa ̧ca
//        cor[u] ← B;
//π[u] ← nulo;
//Fim-Para
//        Para u = 1 ate n fa ̧ca
//        Se cor[u] = B ent ̃ao
//        VisitaBFS(u);
//Fim-se
//        Fim-para
//
//        Algoritmos B ́asicos em Grafos
//        Algoritmo de visita da BFS

//VisitaBFS(u)
//cor[u] ← C;
//d[u] ← 0;
//Q ← {u};
//Enquanto Q <> ∅ fa ̧ca
//        u ← Desenfila(Q)
//Para to.do v ∈ Adj[u] faca
//        Se cor[v] = B ent ̃ao
//        cor[v] ← C;
//π[v] ← u;
//d[v] ← d[u] + 1;
//Enfileira(Q, v);
//Fim-se
//        Fim-para
//        cor[u] ← P;
//Fim-enquanto

#include <iostream>
#include <fstream>
#include <list>
#include <sstream>
#include <string>
#include <algorithm>
#include "BFS.hpp"
#include "DFS.hpp"

#define READ_FROM_FILE      1
#define MANUAL_INSERTION    2

int main() {
    std::string vertices;
    std::list <std::string> edges;


    std::cout << "------ BFS and DFS search Activity -----" << std::endl;
    std::cout << "Enter 1 to read from file or 2 to enter manually: ";
    int option;
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    BFS<std::string> bfs;
    DFS<std::string> dfs;

    if (option == MANUAL_INSERTION){
        std::cout << "Enter the vertices list separated by commas: ";
        std::cin >> vertices;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout
        << "Enter the edges list separated by commas in the following format (vi, vf). "
           "To stop inserting vertices just enter an empty value:"
        << std::endl;

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
        bfs.addVertex(v);
        dfs.addVertex(v);
        std::cout << "Vertex " << v << " added." << std::endl;
    }

    for(auto e : edges){
        std::string v_origin, v_destiny;
        std::stringstream edge_stream(e);
        getline(edge_stream, v_origin, ',');
        getline(edge_stream, v_destiny, ',');
        v_origin.erase(std::remove(v_origin.begin(), v_origin.end(), '('), v_origin.end());
        v_destiny.erase(std::remove(v_destiny.begin(), v_destiny.end(), ')'), v_destiny.end());
        bfs.addEdge(v_origin, v_destiny);
        dfs.addEdge(v_origin, v_destiny);
        std::cout << "Edge (" << v_origin << ", " << v_destiny << ") added." << std::endl;
    }

    std::cout << "BFS search:" << std::endl;
    bfs.search();

    std::cout << "DFS search:" << std::endl;
    dfs.search();

    return 0;
}
