#include <iostream>
#include <queue>
using namespace std;

#include "adjmatrix.h"
#include "adjlist.h"

// Helper to print shortest path in Dijkstra
void printPath(int prev[], int v) {
    if (v == -1) return;
    printPath(prev, prev[v]);
    cout << v << " ";
}

void dijkstra(ListGraph& G, int start, int V) {
    int dist[10], prev[10];
    bool visited[10] = {false};

    for (int i = 0; i < V; i++) {
        dist[i] = -1;
        prev[i] = -1;
    }
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;

        ListGraph::Node* temp = G.getAdjList()[u];
        while (temp != nullptr) {
            int v = temp->vertex;
            int w = temp->weight;
            if (!visited[v] && (dist[v] == -1 || dist[u] + w < dist[v])) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push({dist[v], v});
            }
            temp = temp->next;
        }
    }

    int end;
    cout << "Enter destination node: ";
    cin >> end;

    if (dist[end] == -1) {
        cout << "No path from " << start << " to " << end << ".\n";
    } else {
        cout << "Shortest distance: " << dist[end] << "\n";
        cout << "Path: ";
        printPath(prev, end);
        cout << "\n";
    }
}

void prim(MatrixGraph& G, int V) {
    int key[10];
    bool mstSet[10] = {false};
    int parent[10];

    for (int i = 0; i < V; i++) {
        key[i] = -1;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min = -1, u = -1;
        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && key[v] != -1 && (min == -1 || key[v] < min)) {
                min = key[v];
                u = v;
            }
        }

        if (u == -1) break;
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            int w = G.getMatrix()[u][v];
            if (w > 0 && !mstSet[v] && (key[v] == -1 || w < key[v])) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    cout << "Prim MST:\n";
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1)
            cout << parent[i] << " - " << i << " : " << G.getMatrix()[parent[i]][i] << "\n";
    }
}


void kruskal(MatrixGraph& G, int V) {
    int parent[10];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    bool visited[10][10] = {false};
    int edges = 0;

    cout << "Kruskal MST:\n";

    while (edges < V - 1) {
        int minWeight = -1, u = -1, v = -1;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                int w = G.getMatrix()[i][j];
                if (w > 0 && !visited[i][j] && (minWeight == -1 || w < minWeight)) {
                    int rootU = i;
                    while (rootU != parent[rootU]) rootU = parent[rootU];
                    int rootV = j;
                    while (rootV != parent[rootV]) rootV = parent[rootV];
                    if (rootU != rootV) {
                        minWeight = w;
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            int rootU = u;
            while (rootU != parent[rootU]) rootU = parent[rootU];
            int rootV = v;
            while (rootV != parent[rootV]) rootV = parent[rootV];
            parent[rootV] = rootU;

            cout << u << " - " << v << " : " << minWeight << "\n";
            visited[u][v] = visited[v][u] = true;
            edges++;
        } else {
            break;
        }
    }
}


int main() {
    int V, option;
    cout << "Enter number of vertices: ";
    cin >> V;

    MatrixGraph GM;
    GM.graph(V);
    ListGraph GL(V);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert Edge\n2. Display Matrix\n3. Display List\n";
        cout << "4. Dijkstra\n5. Prim\n6. Kruskal\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> option;

        if (option == 1) {
            int u, v, w;
            cout << "Enter edge (from to weight): ";
            cin >> u >> v >> w;
            GM.insert(u, v, w);
            GL.insert(u, v, w);
        }
        else if (option == 2) {
            GM.display();
        }
        else if (option == 3) {
            GL.display();
        }
        else if (option == 4) {
            int start;
            cout << "Enter start node: ";
            cin >> start;
            dijkstra(GL, start, V);
        }
        else if (option == 5) {
            prim(GM, V);
        }
        else if (option == 6) {
            kruskal(GM, V);
        }
        else if (option == 7) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
