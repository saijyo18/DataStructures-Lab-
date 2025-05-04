// Program to implement a queue using singly linked list
#include<iostream>
using namespace std;


class Queue {
    private:

    struct Node {
        int data;
        Node* next;

        Node (int val) {
            data = val;
            next = NULL;
        }
    };

    Node* head;
    Node* tail;

    public:

    Queue() {
        head = tail = NULL;
    }

    void enqueue(int value);
    void dequeue();
    void peek();
    void display();

};

//Main function

int main() {
    Queue q;
    int choice , value;

    do {
        cout << "MENU: " << endl;
        cout << "1. Enqueue " << endl;
        cout << "2. Dequeue " << endl;
        cout << "3. Peek   "  << endl;
        cout << "4. Display " << endl;
        cout << "5. Exit   "  << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                    cout << "Enter the value you want to enqueue in the list: ";
                    cin  >> value;
                    q.enqueue(value);
                    cout << "The element has been enqueued." << endl;
                    break;

            case 2:
                    q.dequeue();
                    cout << "The element has been dequeued." << endl;
                    break;
                
            case 3:
                    cout << "The front of the queue is: ";
                    q.peek();
                    break;

            case 4:
                    q.display();
                    break;

            case 5:
                    cout << "Exciting the program..." << endl;
                    break;

        }


} while(choice != 5);

return 0;
}

void Queue::enqueue(int value) {
    Node* newnode = new Node(value);

    if ( head == NULL) {
        head = tail = newnode;
    } else {
        Node* temp = tail;
        tail->next = newnode;
        tail = newnode;
    }
}

void Queue::dequeue(){
    if ( head == NULL) {
        cout << "The queue is empty. Cannot dequeue any element." << endl;
        return;
    } else {
        Node* temp = head;
        head = head->next;
        temp->next =NULL;
        delete temp;
    }
}

void Queue::peek() {
    cout << head->data << endl;
}

void Queue::display() {
    Node* temp = head;
    while( temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}