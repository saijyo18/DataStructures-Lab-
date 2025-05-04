// Program to implement stack ADT using SLL
#include<iostream>
#include<stdio.h>
using namespace std;
//class
class stack {

    struct Node {   //properties 
        char data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }

    };

    Node* head;
    public: 
    stack() {
        head  = NULL;
    }
//Member functions 
    void push(char val);
    char pop();
    char peek();
    void display();
};

int main(){
    char value;
    int choice, number;
    stack st;


do {
    cout << "MENU" << endl;
    cout << "1. PUSH" << endl;
    cout << "2. POP"  << endl;
    cout << "3. PEEK" << endl;
    cout << "4. DISPLAY" << endl;
    cout << "5. EXIT" << endl;
    cout << "Choose an option from the above menu: ";
    cin >> choice;
    switch (choice) {
        case 1:
        cout << "Enter the element to push : ";
        cin >> value;
        st.push(value);
        break;

        case 2:

        cout << "The element popped is :" << st.pop() << endl;

        break;

        case 3:
        cout << "The element on top of the stack is: " << st.peek() << endl;
        break;

        case 4:
        st.display();
        break;

        case 5:
        cout << "Exciting the program..." << endl;
        break;

    };

} while(choice != 5);

return 0;

}

//Member function definitions 
void stack::push(char val){
    Node* newnode = new Node(val);
    if( head == NULL)
    {
        head = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }

}

void stack::display(){
    Node* temp = head;
    while( temp != NULL){
        cout << temp->data << "->";
        temp =  temp->next;
    }
    cout << "NULL" <<  endl;

}

char stack::pop(){
    int popp;
    if( head == NULL){

        return '\0';
    }
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    popp = temp->data;
    delete temp;
    return popp;

}

char stack::peek(){
    if( head == NULL){
        return '\0';
    } else {
    return head->data;
    }
}