//
// Created by Gabriel Fonte on 09/07/24.
//

#ifndef INC_10_BFS_DFS_BFS_HPP
#define INC_10_BFS_DFS_BFS_HPP

#include "Graph.hpp"
#include <queue>
#include <iostream>

template <typename T>
class BFS : public Graph<T> {
protected:
    void visit(int node) {
        this->nodes[node].color = 'G';
        this->nodes[node].distance = 0;

        std::queue<int> q;
        q.push(node);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            std::cout << "Visited node " << this->nodes[u].value << " with distance " << this->nodes[u].distance << std::endl;
            for(auto v: this->adj[u]){
                if(this->nodes[v->position].color == 'B'){
                    this->nodes[v->position].color = 'G';
                    this->nodes[v->position].distance = this->nodes[u].distance + 1;
                    q.push(v->position);
                }
            }
            this->nodes[u].color = 'P';
        }
    }

public:
    /* Constructor */
    BFS() : Graph<T>() {}

    /* Breadth-first search */
    void search() {
        for(int i = 0; i < this->vertices; i++){
            this->nodes[i].color = 'B';
            this->nodes[i].distance = -1;
        }
        for(int i = 0; i < this->vertices; i++){
            if(this->nodes[i].color == 'B'){
                this->visit(i);
            }
        }
    }
};

#endif //INC_10_BFS_DFS_BFS_HPP
