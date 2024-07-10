//
// Created by Gabriel Fonte on 09/07/24.
//

#ifndef INC_10_BFS_DFS_DFS_HPP
#define INC_10_BFS_DFS_DFS_HPP

#include "Graph.hpp"
#include <iostream>

template <typename T>
class DFS: public Graph<T> {
private:
    int t;

protected:
    void visit(int node) {
        this->nodes[node].color = 'G';
        this->nodes[node].distance = t;

        std::cout << "Initial time: " << t << std::endl;
        t = t + 1;

        for(auto v: this->adj[node]){
            if(this->nodes[v->position].color == 'B'){
                std::cout << "Visited node " << this->nodes[v->position].value << std::endl;
                this->visit(v->position);
            }
        }
        std::cout << "Final time: " << t << std::endl;
        t = t + 1;
        this->nodes[node].color = 'P';
    }

public:
    /* Constructor */
    DFS() : Graph<T>() {}

    /* Depth-first search */
    void search() {
        for(int i = 0; i < this->vertices; i++){
            this->nodes[i].color = 'B';
            this->nodes[i].distance = -1;
        }
        t = 0;
        for(int i = 0; i < this->vertices; i++){
            if(this->nodes[i].color == 'B'){
                std::cout << "Visited node " << this->nodes[i].value << std::endl;
                this->visit(i);
            }
        }
    }
};


#endif //INC_10_BFS_DFS_DFS_HPP
