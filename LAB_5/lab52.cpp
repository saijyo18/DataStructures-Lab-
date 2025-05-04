#include<iostream>
#include<stdio.h>
using namespace std;

class list {
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

    list(){
          head = tail = NULL;
    }
    //Functions or member functions prototype
    void insertion_beginning(int val);
    void insertion_position(int pos, int value);
    void insertion_end(int val);
    void deletion_beginning();
    void deletion_position(int pos);
    void deletion_end();
    int search(int key);
    void display();


};

int main() {

   int choice;
   int number,value,position;
   list l1;

   do {
   cout  << "MENU:" << endl;
   cout << "1. Insertion at beginning " << endl;
   cout << "2. Insertion at position " << endl;
   cout << "3. Insertion at end " << endl;
   cout << "4. Deletion at beginning " << endl;
   cout << "5. Deletion at position " << endl;
   cout << "6. Deletion at end " << endl;
   cout << "7. Search " << endl;
   cout << "8. Display " << endl;
   cout << "9. Exit" << endl;

   cout << "Choose an option from the above menu: ";
   cin >> choice;


   switch (choice) {

            case 1:
            cout << "Enter the number of elements you want to enter in the list : ";
            cin >> number;
            for( int i=0 ; i < number ; i++){
                printf("Enter %d number: ", i+1);
                scanf("%d",&value);
                l1.insertion_beginning(value);
            }
            break;

            case 2:
            cout << "Enter the position at which you want to insert the element:";
            cin >> position;
            cout << "Enter the element you want to enter in the list:";
            cin >> number;
            l1.insertion_position(position, number);
            break;


            case 3:
            cout << "Enter the element you want to insert at the end: ";
            cin >> value;
            l1.insertion_end(value);
            break;
            

            case 4:
            l1.deletion_beginning();
            break;


            case 5:
            cout << "Enter the position at which you want to delete the element:";
            cin >> position;
            l1.deletion_position(position);
            break;


            case 6:
            l1.deletion_end();
            break;

            case 7:
            cout << "Enter the element you want to search:";
            cin >> number;
            cout << "The elment is found at index :" << l1.search(number) << endl;
            break;


            case 8:
            l1.display();
            break;

            case 9:
            cout << "Exciting the program...." << endl;
            break;

   }

} while(choice != 9);


return 0;
}

void list::insertion_beginning(int val) {
    Node* newnode = new Node(val);
    if(head == NULL) {
        head = tail = newnode;
        tail->next = head;
        return;
    }else {
        newnode->next = head;
        head = newnode;
        tail->next = head;
    }
}

void list::display(){
    if(head == NULL) {
        return;
    }
    cout << head->data << "->";
    Node* temp = head->next;
    
    while( temp != head){
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << temp->data << endl;

}

void list::insertion_position(int pos, int value){
    if(pos == 0){
        insertion_beginning(value);
        return;
    } else {
        Node* temp = head;
        for( int i = 0 ;i < pos-1; i++){
            temp = temp->next;
        }
        Node* newnode = new Node(value);
        newnode->next = temp->next;
        temp->next = newnode;

    }
}

void list::insertion_end(int val){
    Node* newnode = new Node(val);

    if( tail == NULL){
        head = tail =newnode;
        tail->next = newnode;
        return;
    } else {
        newnode->next = head;
        tail->next = newnode;
        tail = newnode;
    }
}

void list::deletion_beginning(){
    if( head == NULL){
        cout  << "List is empty, cannot delete any element.";
        return;
    if( head == tail){
        delete head;
        head = tail = NULL;
    }else {
        Node* temp = head;
        head = head->next;
        tail->next = head;
        temp->next = NULL;
        delete temp;
    }

}
}

void list::deletion_end(){
    if(head == NULL){
        cout << "The list is empty, cannot delete any element.";
        return;
    }
    if( head == tail){
        delete head;
        head = tail = NULL;
    } else {
        Node* temp = tail;
        Node* prev = head;

        while(prev->next != tail){
            prev = prev->next;
        }
        tail = prev;
        tail->next = head;
        temp->next = NULL;
        delete temp;
    }
    
}

void list::deletion_position(int pos){
    Node* temp = head;
    if( head == NULL){
        cout << "List is empty, cannot delete any element."<< endl;
    } else{
        for( int i=0; i < pos -1 ; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }

}

int list::search(int key){
    if( head->data == key){
        return 0;
    }
    Node* temp = head->next;
    int idx = 0;

    while(temp != head){
        if(temp->data == key){
            return idx+1;
        }
        temp = temp->next;
        idx++;
    }

    return -1;
}

