//
// Created by Gabriel Fonte on 09/07/24.
//

#ifndef INC_10_BFS_DFS_GRAPH_HPP
#define INC_10_BFS_DFS_GRAPH_HPP

#include <cstdlib>
#include <vector>
#include <iostream>

template <typename T>
struct Node {
    char color;
    int distance;
    int position;
    T value;
};

template <typename T>
class Graph {
protected:
    std::vector<Node<T>> nodes; // Nodes
    std::vector<std::vector<Node<T>*>> adj; // Adjacency list
    int vertices; // Number of vertices
    int edges; // Number of edges

public:
    Graph(){
        this->vertices = 0;
        this->edges = 0;
    }

    void addVertex(T value){
        Node<T> node;
        node.color = 'B';
        node.value = value;
        node.position = this->vertices;

        if(this->getVertexPos(value) >= 0){
            std::cout << stderr << "Vertex already exists" << std::endl;
            return;
        }

        this->nodes.push_back(node);
        this->adj.push_back(std::vector<Node<T>*>());
        this->vertices++;
    }

    void addEdge(T v, T w){
        int v_pos = this->getVertexPos(v);
        int w_pos = this->getVertexPos(w);

        if (v_pos < this->vertices) {
            if(w_pos < this->vertices) {
                this->adj[v_pos].push_back(&(this->nodes[w_pos]));
            }
            else {
                std::cout << stderr << "Vertex " << w << " not found" << std::endl;
                return;
            }
        } else {
            std::cout << stderr << "Vertex " << v << " not found" << std::endl;
            return;
        }

        this->edges++;
    }

    int getVertexPos(T value){
        for (auto node : this->nodes) {
            if (node.value == value) {
                return node.position;
            }
        }
        return -1;
    }
};


#endif //INC_10_BFS_DFS_GRAPH_HPP
