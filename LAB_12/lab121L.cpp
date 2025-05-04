//Program to implement graph adt usung adjacent matrix

#include<iostream>
using namespace std;

const int MAX = 100;
int adj[MAX][MAX] = {0};
int vertices;

void insertedge(int u, int v) {
    if ( u >= vertices || v >= vertices || u < 0 || v < 0) {
        cout << "Invalid source or destination.Please try again." << endl;
        return;
    }
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void deleteedge( int u, int v) {
    if ( u >= vertices || v >= vertices || u < 0 || v < 0) {
        cout << "Invalid source or destination.Please try again." << endl;
        return;
    }
    adj[u][v] = 0 ;
    adj[v][u] = 0;
}

void searchedge(int u , int v) {
     if ( u >= vertices || v >= vertices || u < 0 || v < 0) {
        cout << "Invalid source or destination.Please try again." << endl;
        return;
    }

    if (adj[u][v]) {
        cout << "Edge is found from " << u << "to" << v << endl;
    } else {
        cout << "Edge is not found." << endl;
    }
}

void displaymatrix() {
    cout << "Adjacent Matrix" << endl;
    for( int i = 0 ; i < vertices ; i++) {
        for( int j = 0 ; j < vertices ; j++ ){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    int choice , u , v;
    cout << "Enter the number of vertices: " ;
    cin >> vertices;

    do {
        cout << "----Graph ADT Menu----" << endl;
        cout << "1. Insert Edge" << endl;
        cout << "2. Delete Edge" << endl;
        cout << "3. Search Edge" << endl;
        cout << "4. Display Matrix" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice from the above menu: ";
        cin >> choice;

        switch (choice) {
                    case 1:
                        cout << "Enter the source and destination edges: ";
                        cin >> u >> v;
                        insertedge(u,v);
                        break;
                    
                    case 2:
                        cout << "Enter the source and destinaton edges: ";
                        cin >> u >> v;
                        deleteedge(u,v);
                        break;
                    
                    case 3:
                        cout << "Enter the source and destination edges: ";
                        cin >> u >> v;
                        searchedge(u,v);
                        break;

                    case 4:
                        displaymatrix();
                        break;

                    case 5:
                        cout << "Exciting the program..." << endl;
                        break;
                    
        }

    } while ( choice != 5);

    return 0;
}