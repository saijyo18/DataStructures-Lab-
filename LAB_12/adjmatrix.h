#ifndef ADJMATRIX_H
#define ADJMATRIX_H
#include <iostream>
using namespace std;

class MatrixGraph {
private:
    int adjmatrix[10][10];
    int V;

public:
    void graph(int vertices) {
        V = vertices;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adjmatrix[i][j] = 0;
    }

    int (*getMatrix())[10] {
        return adjmatrix;
    }

    int getV() { return V; }

    void insert(int x, int y, int weight) {
        if (x >= V || y >= V || x < 0 || y < 0) {
            cout << "Invalid Edge.\n";
            return;
        }
        adjmatrix[x][y] = weight;
    }

    void display() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                cout << adjmatrix[i][j] << " ";
            cout << "\n";
        }
    }
};
#endif
