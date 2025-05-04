//Program to implement separate chaining 

#include <iostream>
#include<algorithm>
#include <list>
using namespace std;

const int TABLE_SIZE = 10;

class hashtable {
    list<int> table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    void insert(int key);
    void remove(int key);
    void search(int key);
    void display();
};

int main() {
    hashtable ht;
    int choice, key;

    do {
        cout << "---- Hash Table Menu ----";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                ht.insert(key);
                ht.display();
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                ht.remove(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                ht.search(key);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

//Function definitions 
void hashtable::insert(int key) {
    int index = hashFunction(key);
    // Avoid duplicate insertion
    for (int val : table[index]) {
        if (val == key) {
            cout << "Key already exists.\n";
            return;
        }
    }
    table[index].push_back(key);
    cout << "Inserted " << key << " successfully.\n";
}

void hashtable::remove(int key) {
    int index = hashFunction(key);
    auto& chain = table[index];
    auto it = find(chain.begin(), chain.end(), key);
    if (it != chain.end()) {
        chain.erase(it);
        cout << "Deleted " << key << " successfully.\n";
    } else {
        cout << "Key not found.\n";
    }
}

void hashtable::search(int key) {
    int index = hashFunction(key);
    for (int val : table[index]) {
        if (val == key) {
            cout << "Key " << key << " found at index " << index << ".\n";
            return;
        }
    }
    cout << "Key not found.\n";
}

void hashtable::display() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << i << " --> ";
        for (int val : table[i])
            cout << val << " -> ";
        cout << "NULL\n";
    }
}