//Program to implement hash adt using linear probing 

#include<iostream>
using namespace std;

class hashtable {
public:

static const int SIZE = 10;
int hashtable[SIZE];
bool occupied[SIZE];

//function defintions 
void initializetable();
int hashfunction(int key);
void insert(int key);
void deletekey(int key);
void search(int key);
void display();

};

int main() {
    hashtable ht;
    ht.initializetable();
    int choice , key;


    do {
            cout << "-----Hash ADT MENU-----" << endl;
            cout << "1. Insert" << endl;
            cout << "2. Delete" << endl;
            cout << "3. Search" << endl;
            cout << "4. Display" << endl;
            cout << "5. Exit"   << endl; 
            cout << "Enter your choice from the above menu: ";
            cin >> choice;

            switch (choice) {
                case 1:
                        cout << "Enter the value you want to insert: ";
                        cin >> key;
                        ht.insert(key);
                        break;
                
                case 2:
                        cout << "Enter the element you want to delete: ";
                        cin >> key;
                        ht.deletekey(key);
                        break;
                
                case 3:
                        cout << "Enter the element you want to search: ";
                        cin >> key;
                        ht.search(key);
                        break;

                case 4:
                        cout << "HASHTABLE" << endl;
                        ht.display();
                        break;

                case 5:
                        cout << "Exciting the program..." << endl;
                        break;
            }
    } while(choice != 5);

    return 0;
}

//Function definitions 
void hashtable::initializetable(){
    for(int i = 0 ;i < SIZE ; ++i){
        hashtable[i] = -1;
        occupied[i] = false;
    }
}

int hashtable::hashfunction(int key) {
    return key % SIZE;
}

void hashtable::insert(int key) {
    int index = hashfunction(key);
    int start = index;

    do {
        if(!occupied[index]) {
            hashtable[index] = key;
            occupied[index] = true;
            cout << "Element is inserted at index " << index << endl;
            return;
         }
         index = (index + 1) % SIZE;
    } while(index != start);

    cout << "The hashtable is full." << endl;
}


void hashtable::deletekey(int key) {
    int index = hashfunction(key);
    int start = index;

    do {
        if( occupied[index] && hashtable[index] == key) {
            occupied[index] = false;
            hashtable[index] = -1;
            cout << "Element deleted at index " << index << endl;
            return;
        }
        index = (index+1) % SIZE;
    } while ( occupied[index] && index != start);

    cout << "The element to be deleted is not found in the list." << endl;
}

void hashtable::search(int key) {
    int index = hashfunction(key);
    int start = index;

    do {
        if ( occupied[index] && hashtable[index] == key) {
            cout << "Element is found at index " << index << endl;
            return;
         } 
         index = ( index + 1) % SIZE;
    } while( occupied[index] && index != start);

    cout << "The element is not found in the list." << endl;

}

void hashtable::display() {
    for (int i = 0 ; i < SIZE ; ++i){
        cout << i << "-->";
        if(occupied[i]) {
            cout << hashtable[i] ;
        } else {
            cout << "Empty";
        }
        cout << endl;
        
    }
}