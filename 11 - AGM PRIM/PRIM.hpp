//
// Created by Gabriel Fonte on 10/07/24.
//

#ifndef INC_11_AGM_PRIM_PRIM_HPP
#define INC_11_AGM_PRIM_PRIM_HPP

//
// Created by Gabriel Fonte on 09/07/24.
//

#ifndef INC_10_BFS_DFS_BFS_HPP
#define INC_10_BFS_DFS_BFS_HPP

#include "Graph.hpp"
#include <queue>
#include <iostream>
#include <limits>

template <typename T>
class PRIM : public Graph<T> {
private:
    std::vector<Node<T>> Q;
    std::vector<std::vector<Node<T>*>> H;
    int weight;

public:
    /* Constructor */
    PRIM() : Graph<T>() {}

    /* PRIM - Minimal Tree Generator */
    void generate_tree(T root) {
        // Q is the set of nodes not yet included in the tree
        Q = this->nodes;
        // H is the set of edges of the AGM
        H = std::vector<std::vector<Node<T>*>>(); // Empty initially
        // weight is the total weight of the AGM
        weight = 0;

        //Initialize the distance of all nodes to infinity
        for(int i = 0; i < this->vertices; i++){
            this->nodes[i].distance = INT_MAX;
        }

        // The root node has distance 0
        this->nodes[this->getVertexPos(root)].distance = 0;

        while(!Q.empty()){
            // Find the node with the smallest distance
            Node<T> u = Q[0];
            for(auto node: Q){
                if(node.distance < u.distance){
                    u = node;
                }
            }
            // Remove u from Q
            Q.erase(std::remove(Q.begin(), Q.end(), u), Q.end());
            // Add the edge to H
            if(u.distance != 0){
                H.push_back({&(this->nodes[u.position]), &(this->nodes[u.pi])});
                weight += u.distance;
            }
            // Update the distance of the adjacent nodes
            for(auto v: this->adj[u.position]){
                if(std::find(Q.begin(), Q.end(), this->nodes[v->position]) != Q.end() && v->distance < this->nodes[v->position].distance){
                    //this->nodes[v->position].pi = u.position;
                    this->nodes[v->position].distance = v->distance;
                }
            }
        }

        // Print the AGM
        std::cout << "Minimal Tree:" << std::endl;
        for(auto edge: H){
            std::cout << edge
        }
    }
};

#endif //INC_10_BFS_DFS_BFS_HPP


#endif //INC_11_AGM_PRIM_PRIM_HPP
