//
// Created by Gabriel Fonte on 10/07/24.
//

#ifndef INC_12_AGM_KRUSKAL_HPP
#define INC_12_AGM_KRUSKAL_HPP

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
    class NodeRelationComparator {
    public:
    bool operator()(const NodeRelation<T> &a, const NodeRelation<T> &b) {
        return a.weight > b.weight;
    }
};

typedef int NodeReference;

template <typename T>
class KRUSKAL : public Graph<T> {
private:
    std::vector<NodeRelation<T> > H;
    std::priority_queue<NodeRelation<T>, std::vector<NodeRelation<T>>, NodeRelationComparator<T>> L;
    std::vector<NodeReference> trees;
    int weight;
    int edges;
    int n;

public:
    /* Constructor */
    KRUSKAL() : Graph<T>() {}

    /* KRUSKAL - Minimal Tree Generator */
    void generate_tree(T root) {
        // H is the set of edges of the AGM
        H = std::vector<NodeRelation<T> >(); // Empty initially
        // weight is the total weight of the AGM
        weight = 0;
        // edges is the number of edges in the AGM
        edges = 0;
        // total number of vertices
        n = this->vertices;
        trees.reserve(n);

        // Initializes the trees containing each node
        for (auto& node : this->nodes) {
            trees[node.position] = node.position;
            for (auto& adj : this->adj[node.position]) {
                L.push({&node, adj.first, adj.second});
            }
        }

        std::cout << "Edges: " << std::endl;

        while(edges != n - 1){
            // find the node with the smallest distance
            auto edge = L.top();
            L.pop();

            auto u = edge.origin;
            auto v = edge.destination;

            if(this->trees[u->position] != this->trees[v->position]){
                std::cout << "Adding edge (" << u->value << ", " << v->value << ") with weight " << edge.weight << std::endl;
                // Add the edge to H
                H.push_back({u, v, edge.weight});
                // Update the total weight of the AGM
                weight += edge.weight;
                // Update the trees
                int old_tree = this->trees[v->position];
                int new_tree = this->trees[u->position];
                for (int i = 0; i < n; i++) {
                    if (this->trees[i] == old_tree) {
                        this->trees[i] = new_tree;
                    }
                }
                // Update the number of edges
                edges++;
            }
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

#endif //INC_12_AGM_KRUSKAL_HPP
