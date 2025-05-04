//Program to implelement a circular queue using an array of size -5
#include<iostream>
using namespace std;

#define SIZE 5

class circularqueue {
    private:
    int queue[SIZE];
    int front, rear;

    public: 

    circularqueue() {
        front = -1;
        rear = -1;
    }
    
    bool isfull();
    bool isempty();
    void enqueue(int value);
    void dequeue();
    void peek();
    void display();
 
};

int main() {
    circularqueue cq;
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
                        cout << "Enter the value: ";
                        cin >> value;
                        cq.enqueue(value);
                        break;


                    case 2:
                        cq.dequeue();
                        break;

                    
                    case 3:
                        cq.peek();
                        break;


                    case 4:
                        cq.display();
                        break;

                    
                    case 5:
                        cout << "Exciting the program..." << endl;
                        break;

        }


    } while(choice != 5);

}


bool circularqueue::isfull() {
    return (rear+1)%SIZE == front;
}


bool circularqueue::isempty() {
    return front == -1 || front > rear;
}


void circularqueue::enqueue(int value) {
    if(isfull()) {
        cout << "The queue is full. Cannot add further element." << endl;
        return;
    }

    if(isempty()) {
        front = rear = 0;
    } else {
        rear = (rear+1)%SIZE;
    }
    cout << "Rear index: " << rear << endl;
    queue[rear] = value;
    cout << "Enqueued:" << value << endl;

}


void circularqueue::dequeue() {
    if(isempty()) {
        cout << "The queue is empty. Cannot deque any element." << endl;
        return;
    }
    cout << "Front index:" << front << endl;
    cout << "Dequeued:" << queue[front] << endl;
    if ( front == rear) {
        front = rear = -1;  //reset the queue to the starting 
    } else {
        front = (front+1)%SIZE;
     }
}

void circularqueue::peek() {
    if(isempty()) {
        cout << "Queue is empty. Cannot display any element." << endl;
        return;
    }
    cout << "Front value: " << queue[front] << endl;
 
}



void circularqueue::display() {
    for(int i = front ; i <= rear ; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}