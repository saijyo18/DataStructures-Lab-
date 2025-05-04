//Program to perform list adt functions
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class listadt {
int arr[5] = {1,2,3,4,5};
int size = 5;

public:
int i; //Member functions prototypes
void insert_beginning(int number);
void insert_ending(int number1);
void insert_position(int position , int value);
void delete_beginning();
void delete_end();
void delete_position(int pos);
void display();
int getsize();
void reverse(int start, int end);
void rotatearray(int kunits);


};




int main() {
int choice;
int number,position,kunits;

cout << "MENU:" << endl;
cout <<"1. Insertion at the beginning\n2. Insertion at the end\n3. Insertion at position" << endl;
cout <<"4. Deletion at the beginning\n5. Deletion at the end\n6. Deletion at the position\n7. Rotate the array\n8. Quit\n" << endl;
cout << "Choose your option from the above menu:";
cin >> choice;
listadt obj;
switch (choice) {
case 1:
cout << "Enter the number you want to insert: " << endl;
cin >> number;
obj.insert_beginning(number);
obj.display();
printf("\n");
break;

case 2:{
cout << "Enter the number you want to insert at the end : " << endl;
cin >> number;
obj.insert_ending(number);
obj.display();

break;

}

case 3:

cout << "Enter the positon at which you want to enter the value: " << endl;
cin >> position;
cout << "Enter the element you want to insert: " << endl;
cin >> number;
obj.insert_position( position, number);
obj.display();
break;

case 4:
obj.delete_beginning();
obj.display();
break;

case 5:

obj.delete_end();
obj.display();
break;

case 6:

cout << "Enter the position at which you want to delete :" << endl;
cin >> position;
obj.delete_position(position);

if ( position < obj.getsize()+2){
obj.display();
}

break;

case 7:

cout << "Enter the units by which ypou want to rotate the array : " << endl;
cin >> kunits;
obj.rotatearray(kunits);
obj.display();
break;

case 8:

cout << "Exiting the program...." << endl;
break;


}
return 0;

}

//MEMBER FUNCTIONS DEFINITION OUTSIDE THE CLASS

void listadt::insert_beginning(int number){
for( i = size; i > 0 ;i--)
{
arr[i] = arr[i-1];
}
arr[0] = number;
}

void listadt::insert_ending(int number1){

arr[size-1] = number1;

}

void listadt::insert_position(int position , int value){

if(position > size ){
cout << "Invalid Positon. Give the size within range." << endl;
return;
}

for( i = size ;i > position-1; i--){
arr[i] = arr[i-1];

}

arr[position-1] = value;

}

void listadt::delete_beginning(){
for(i = 0; i <(size)-1 ; i++){
arr[i] = arr[i+1];
}
size--;
}

void listadt::delete_end(){
size--;

}


void listadt::display(){
int i;
for( i = 0; i < size ; i++ ){
cout << arr[i] <<" ";
}
printf("\n");
}

void listadt::delete_position(int pos){
int i;
if(pos > size){
cout << "Invalid Positon. Give the size within range." << endl;
return;
}

for(i = pos -1; i < size ; i++){
arr[i] = arr[i+1];
}
size--;

}

int listadt::getsize(){ // TO ACCESS THE PRIVATE
return size;
}

void listadt::reverse(int start, int end) {
    while (start < end) {
        int temp;
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void listadt::rotatearray( int kunits) {
    kunits = kunits % size; 
    reverse(0, kunits - 1);
    reverse( kunits, size - 1);
    reverse( 0, size - 1);
}
