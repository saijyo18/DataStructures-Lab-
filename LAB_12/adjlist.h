#ifndef ADJLIST_H
#define ADJLIST_H
#include <iostream>
using namespace std;

class ListGraph {
public:
    class Node {
    public:
        int vertex;
        int weight;
        Node* next;
        Node(int v, int w) : vertex(v), weight(w), next(nullptr) {}
    };

private:
    int V;
    Node** adjlist;

public:
    ListGraph(int vertices) {
        V = vertices;
        adjlist = new Node*[V];
        for (int i = 0; i < V; i++)
            adjlist[i] = nullptr;
    }

    int getV() { return V; }

    Node** getAdjList() {
        return adjlist;
    }

    void insert(int x, int y, int weight) {
        Node* newNode = new Node(y, weight);
        newNode->next = adjlist[x];
        adjlist[x] = newNode;
    }

    void display() {
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            Node* temp = adjlist[i];
            while (temp != nullptr) {
                cout << "(" << temp->vertex << ", w=" << temp->weight << ") -> ";
                temp = temp->next;
            }
            cout << "null\n";
        }
    }
};
#endif
