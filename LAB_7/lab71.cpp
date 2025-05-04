//Program to implement a queue using array of size 5

#include<iostream>
using namespace std;

#define SIZE 5

class Queue {
    private: 
    int queue[SIZE];
    int front , rear;

    public :

    Queue() {
        front = -1;
        rear = -1;
    }

   //METHODS OR FUNCTION PROPERTIES 
    bool isfull();
    bool isempty();
    void enqueue(int value);
    void dequeue();
    void peek();
    void display();

};

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
                        cout << "Enter the value you want to enqueue: ";
                        cin >> value;
                        q.enqueue(value);
                        break;

                case 2:
                        q.dequeue();
                        break;

                case 3:
                        q.peek();
                        break;

                case 4:
                        q.display();
                        break;

                case 5:
                        cout << "Exciting the progrm..." << endl;
        

        }

    } while( choice != 5);

    return 0;
}

//METHODS DEFINITION 

bool Queue::isfull(){
    return rear == SIZE-1;
}

bool Queue::isempty(){
    return front == -1 || front > rear;
}

void Queue::enqueue(int value) {
    if(isfull()){
        cout << "rear:" << rear << endl;
        cout << "Queue is full. Cannot enter any elements further." << endl;
        return;
    }
    if(isempty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
    cout << "Enqueued:" << value << endl;
}

void Queue::dequeue() {
    if(isempty()){
        cout << "The queue is empty. Cannot dequeue any element. " << endl;
        return;
    }
    cout << "Front index: " << front << endl;
    cout << "Dequeued:" << queue[front] << endl;
    front++;

    if( front > rear){
        front = rear = -1;
    }
     
}

void Queue::peek() {
    if(isempty()){
        cout << "The queue is empty." << endl;
        return;
    } else {
        cout << "Front value:" << queue[front] << endl;
    }
}

void Queue::display() {
    if(isempty()) {
        cout << "The queue is empty." << endl;
        return;
    }

    cout << "The queue:";
    for( int i = front ; i <= rear ; i++){
        cout << queue[i] << " ";
    }
    cout << endl;
} 