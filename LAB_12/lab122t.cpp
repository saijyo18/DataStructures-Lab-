//Program to implement graph adt using adjacent list

#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph {
    int V;
    vector<list<int>> adjlist;

    public:

    Graph(int V) {
        this->V= V;
        adjlist.resize(V);
    }

    void insertedge(int v, int w) {
        if( v >= V || w >= V || v < 0 || w < 0) {
            cout << "Invalid vertices. Please enter different values." << endl;
            return;
        }
        
        adjlist[v].push_back(w);
        cout << "Edge has been inserted from " << v << " to " << w << endl;
        
    }

    void deleteedge(int v , int w){
        if( v >= V || w >= V || v < 0 || w < 0) {
            cout << "Invalid index. Plase enter different value. " << endl;
            return;
        }

        adjlist[v].remove(w);
        cout << "Edge has been removed from " << v << " to " << w << endl;

    }

    void searchedge(int v , int w) {
         if( v >= V || w >= V || v < 0 || w < 0) {
            cout << "Invalid index. Plase enter different value. " << endl;
            return;
        }

        for( int i : adjlist[v]) {
            if( i == w) {
                cout << "Edge is found from " << v << " to " << w << endl;
            }
        }
        cout << "Edge not found." << endl;
    }

    void display() {
        cout << "Adjacent List: " << endl;
        for ( int i = 0 ; i < V ; i++) {
            cout << i << "--->";
            for(int j : adjlist[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V, choice , v , w;
    cout << "Enter the number of vertices: ";
    cin >> V;

    Graph g(V);

    do {
        cout << "----Graph ADT Menu----" << endl;
        cout << "1. Insert Edge" << endl;
        cout << "2. Delete Edge" << endl;
        cout << "3. Search Edge" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice from the above menu: ";
        cin >> choice;

        
        switch (choice) {
                case 1:
                    cout << "Enter the source and destination edges: ";
                    cin >> v >> w;
                    g.insertedge(v,w);
                    break;

                case 2:
                    cout << "Enter the source and destination edges: ";
                    cin >> v >> w;
                    g.deleteedge(v,w);
                    break;

                case 3:
                    cout << "Enter the source and destination edges: ";
                    cin >> v >> w;
                    g.searchedge(v,w);
                    break;

                case 4:
                    g.display();
                    break;

                case 5:
                    cout << "Exciting the program..." << endl;
                    break;
        }

    }while ( choice != 5);
    
   return 0;
}