//Program to implement a singly linked list and its functions from scratch using singly linked list 
#include<iostream>
#include<stdio.h>
using namespace std;


class list {
    private:
    struct Node {
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }
    };

    Node* head;
    Node* tail;

    public:
    list() {
        head = tail = NULL;
    }

    void insert_beginning(int value);
    void display();
    void insert_end(int value);
    void insert_position(int position,int value);
    void delete_beginning();
    void delete_end();
    int search(int key );
    void delete_position(int position);
    void reverselist();

};

int main() {
 
 int choice,  number , value;
 list l1;

 do {
    cout << "MENU" << endl;
    cout << "1. Insert at beginning " << endl;
    cout << "2. Insert at end " << endl;
    cout << "3. Insert at Position " << endl;
    cout << "4. Delete at beginnig " << endl;
    cout << "5. Delete at position " << endl;
    cout << "6. Delete at end " << endl;
    cout << "7. Search " << endl;
    cout << "8. Reverse the list " << endl;
    cout << "9. Display " << endl;
    cout << "10. Exit" << endl;

    cout << "Choose an option from  the above: " <<  endl;
    cin >> choice ;

 switch (choice) {
         case 1: // Insertion at the beginning 
            int i;
            printf("Enter the number of elements you want to eneter in the list: ");
            scanf("%d" , &number);
            for(i=0;i < number ; i++){
            printf("Enter the %d element : ", i);
            scanf("%d", &value);
            l1.insert_beginning(value);
    }
            break;

         case 2: //Insertion at the end 
            printf("Enter the element you want to enter in the end: ");
            scanf("%d", &value);
            l1.insert_end(value);
            break;
            

         case 3: // Insertion at the position 
            int  position, num;
            cout << "Enter the position :" << endl;
            cin >> position;
            cout << "Enter the value :" << endl;
            cin >> num;
            l1.insert_position(position,num);
            break;


         case 4: // deletion at the beginning 
            cout << "After deletion at the beginnig the list is: " << endl;
            l1.delete_beginning();
            break;

         case 5: //deletion at the position 
            int pos;
            cout << "Enter the position : " << endl;
            cin >> pos;
            l1.delete_position(pos);
            break;
            

         case 6: //deletion at the end 
            cout << "After deletion at the end, the list is :" << endl;
            l1.delete_end();
            break;
 
         case 7:  //To search an element
            int key;
            cout << "Enter the element you want to search : " << endl;
            cin >> key;
            cout << "the element is found at index: " << l1.search(key) << endl;
            break; 
         case 8:
            l1.reverselist();
            break;

         case 9: //display function 
            l1.display();
            break;
    
         case 10: //exit the program 
            cout << "Exciting the program..." << endl;
            break;

 } 
} while(choice != 10 ) ;


return 0;
}

void list::insert_beginning(int value) {
        Node* newnode = new Node(value);
        if(head == NULL) {
            head = tail = newnode;
            return;
        }else{
            newnode->next = head;
            head = newnode;
        }
    }
    
void list::display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

void list::insert_end(int value){
    Node* newnode = new Node(value);
    if(head == NULL){
        head = tail = newnode;
    }else {
        tail->next = newnode;
        tail = newnode;
    }

}

void list::insert_position(int position, int value){
    
    if(head == NULL){
        cout << "Head is empty cannot insert an element." << endl;

    }else{
        Node* temp = head;
        for(int i =0 ; i< position-1 ; i++){
             temp = temp->next;
        }
        Node* newnode = new Node(value);
        newnode->next = temp->next;
        temp->next = newnode;
    }

}

void list::delete_beginning(){
    if(head == NULL){
        printf("The list is empty cannot delete anything. Try again.");

    } else{
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
}

void list::delete_end(){
    if(head == NULL){
        cout << "List is empty, cannot delete anything."<< endl;
    }else{
        Node* temp =head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
}

int list::search(int key) {
    Node *temp = head;
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

void list::delete_position(int position){
    if(head == NULL){
        cout << "The list is empty , cannot delete anything. " << endl;

    }else{
        Node* temp = head;
        for(int i =0 ; i< position -1 ; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
}

void list::reverselist(){
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
