#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class List {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head1;
    Node* head2;

public:
    List();  // Only declare the constructor here
    void insert_beginning(Node*& head, int val);
    void display(Node* head);
    Node* mergesortedlists(Node* head1, Node* head2);
    void displaym();
    
    Node*& gethead1();
    Node*& gethead2();
};

#endif // LIST_H
