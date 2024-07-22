//
// Created by Gabriel Fonte on 10/07/24.
//

#ifndef INC_11_AGM_PRIM_PRIM_HPP
#define INC_11_AGM_PRIM_PRIM_HPP

#include "Graph.hpp"
#include <iostream>
#include <limits>
#include <algorithm>
#include <queue>

template <typename T>
struct NodeRelation {
    Node<T>* origin;
    Node<T>* destination;
    int weight;
};

template <typename T>
class PRIM : public Graph<T> {
private:
    std::priority_queue<Node<T>*, std::vector<Node<T>*>, GraphAlgorithms::MinHeapComparator<T> > Q; // Q is a priority queue of pointers to the nodes of the underlying graph
    std::vector<NodeRelation<T> > H; // H is a vector of relation of nodes under the underlying graph and its weight
    int weight;

public:
    /* Constructor */
    PRIM() : Graph<T>() {}

    /* PRIM - Minimal Tree Generator */
    void generate_tree(T root) {
        // Q is the set of nodes not yet included in the tree
        for (auto& node : this->nodes) {
            Q.push(&node);
        }
        //Initialize the distance of all nodes to infinity
        for(int i = 0; i < this->vertices; i++){
            this->nodes[i].distance = INT_MAX;
        }
        // The root node has distance 0
        this->nodes[this->getVertexPos(root)].distance = 0;

        // H is the set of edges of the AGM
        H = std::vector<NodeRelation<T> >(); // Empty initially
        // weight is the total weight of the AGM
        weight = 0;

        while(!Q.empty()){
            // find the node with the smallest distance
            auto u = Q.top();
            std::cout << "Get node " << u->value << " with distance " << u->distance << std::endl;

            // Update the total weight of the AGM
            weight += u->distance;
            // Add the edge to H
            //H.push_back({&(this->nodes[u->pi]), &(this->nodes[u->position]), u->distance});
            H.push_back(
                {
                    &(this->nodes[u->pi]),
                    &(this->nodes[u->position]),
                    u->distance
                }
            );

            // Update the distance of the adjacent nodes
            for(auto v: this->adj[u->position]){
                auto uv_weight = v.second;
                if(this->nodes[v.first->position].distance > uv_weight){
                    std::cout << "Updating distance of node " << v.first->value << " to " << v.second << std::endl;
                    this->nodes[v.first->position].distance = uv_weight;
                    this->nodes[v.first->position].pi = u->position;
                    std::cout << "pi(" << this->nodes[v.first->position].value << ") = " << this->nodes[this->nodes[v.first->position].pi].value << std::endl;
                }
            }

            // pop the smallest node
            Q.pop();
        }

        // Print the AGM
        std::cout << std::endl;
        std::cout << "Minimal Tree:" << std::endl;
        for(auto edge: H){
            std::cout << "(" << edge.origin->value << ", " << edge.destination->value << ") with weight "
            << edge.weight << std::endl;
        }

        // Print the total weight of the AGM
        std::cout << "Total weight: " << weight << std::endl;
    }
};

#endif //INC_11_AGM_PRIM_PRIM_HPP
