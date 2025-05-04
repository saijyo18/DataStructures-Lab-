//Program to imoplement a doubly linked list from scratch using a tail pointer 
#include<iostream>
#include<stdio.h>
using namespace std;

class doublylist {
    private:
    //Data memebers 
    struct Node {
        int data;
        Node* next;
        Node* prev;

        Node(int val){
            data = val;
            next = prev = NULL;
        }
    };

    Node* head;
    Node* tail;

    public:
    doublylist() {
        head = tail = NULL;
    }

    //Member function prototypes 
    void insertion_beginning(int val);
    void insertion_end(int val);
    void insertion_position(int pos, int val);
    void deletion_beginning();
    void deletion_position(int pos);
    void deletion_end();
    int search(int key);
    void display();

};

int main() {
   
   int choice;
   int number,value,position;
   doublylist l1;

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
                for( int i =0 ;i < number ; i++ ){
                    printf("Enter element %d:",i+1);
                    scanf("%d", &value);
                    l1.insertion_beginning(value);
                }
                break;

                case 2:
                cout << "Enter the positon at which you want to insert the element: ";
                cin >> position;
                cout << "Enter the number you want to enter: ";
                cin >> number;
                l1.insertion_position(position,number);
                break;


                case 3:
                cout << "Enter the element you want to insert at the end: ";
                cin >> number;
                l1.insertion_end(number);
                break;

                case 4:
                l1.deletion_beginning();
            
                break;

                case 5:
                cout << "Enter the position at which you want to delete the element: ";
                cin >> number;
                l1.deletion_position(number);
                break;


                case 6:
                cout << "The element is deleted from the end of the list. " << endl;
                cout << "Choose option 8 to display the list." << endl;
                l1.deletion_end();
                break;

                case 7:
                cout << "Enter the number you want to search in the list: " ;
                cin >> number;
                cout << "the element is found at index: " << l1.search(number) << endl;
                break;


                case 8:
                l1.display();
                break;

                case 9:
                cout << "Exciting the program..." << endl;
                break;

   }
} while(choice != 9);



   return 0;

}

//Member function definitions 
void doublylist::insertion_beginning(int val) {
           Node* newnode = new Node(val);

           if( head == NULL){
            head = tail = newnode;
            return;
           } else {

            newnode->next = head;
            head->prev = newnode;
            head = newnode;

           }

}

void doublylist::display(){

    Node* temp = head;
    cout << "Printed forward: ";
    while( temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    Node* temp1 = tail;
    cout << "Printed reverse: ";
    while( temp1 != NULL){
        cout << temp1->data << "->" ;
        temp1 = temp1->prev;
    }
    cout << "NULL" << endl;


}

void doublylist::insertion_end(int val) {
    Node* newnode = new Node(val);

    if(head == NULL){
        head = tail = newnode;
        return;
    } else{

          newnode->prev = tail;
          tail->next = newnode;
          tail = newnode;
    }
    }

    void doublylist::insertion_position(int pos, int val){
        Node* newnode = new Node(val);
        if( head == NULL){
            head = tail = newnode;
            return;
        }

        if( pos == 0){
            insertion_beginning(val);
            return;
        }

        Node* temp = head;
        
        for( int i =0 ; i < pos-1; i++){
            temp = temp->next;
        }
            newnode->next = temp->next;
            newnode->prev = temp;
            temp->next->prev = newnode;
            temp->next  = newnode;
            
    }

    void doublylist::deletion_beginning(){
           Node* temp = head;
              if(head == NULL){
                cout << "The list is empty , cannot delete anything. " << endl;
                return;
              } else {
                 head = head->next;
                 if( head != NULL)
                    head->prev = NULL;
                 temp->next = NULL;
                 delete temp;
              }
    }

    void doublylist::deletion_position(int pos){
      Node* temp = head;
      Node* temp1= head;
      if( head == NULL){
        cout << "The list is empty, cannot delete anything." << endl;
        return;
      } else {
        for( int i = 0 ;i < pos-1; i ++){
            temp = temp->next;
        }
        temp->next->prev = NULL;
        temp->next = temp->next->next;
        temp1= temp->next;
        temp1->prev->next = NULL;
        temp1->prev = temp;
      }
}

    void doublylist::deletion_end(){
        Node* temp = tail;
        if( head == NULL){
            cout << "The list is empty , cannot delete anything. " << endl;
            return;
        } else {
              tail = tail-> prev;
              if( tail != NULL)
                tail->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
    }

    int doublylist::search(int key) {
        Node* temp = head;
        int idx =0;

         while(temp!=NULL){
          if(temp->data == key){
            return idx;
        }
        temp = temp->next;
        idx++;
    }
    return -1;

    }