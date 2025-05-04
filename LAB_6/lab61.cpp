// Program to implement stack ADT using vectors with char

#include<iostream>
#include<vector>
using namespace std;

class stack {
    vector<char> arr;

public:
   //Member functions 
    void push(char val);
    void pop();
    char peek();
    void display();
};

int main() {
    char value;
    int choice;
    stack st;

    do {
        cout << "MENU" << endl;
        cout << "1. PUSH" << endl;
        cout << "2. POP" << endl;
        cout << "3. PEEK" << endl;
        cout << "4. DISPLAY" << endl;
        cout << "5. EXIT" << endl;
        cout << "Choose an option from the above menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the character to push: ";
                cin >> value;
                st.push(value);
                break;

            case 2:
                st.pop();
                cout << "The element is popped, choose display to view the list" << endl;
                break;

            case 3:
                cout << "The top of the stack is: " << st.peek() << endl;
                break;

            case 4:
                st.display();
                break;

            case 5:
                cout << "Exiting the program..." << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}

//Function definitions 
void stack::push(char val) {
    arr.push_back(val);
}

void stack::pop() {
    if (!arr.empty()) {
        arr.pop_back();
    } else {
        cout << "Stack is empty. Cannot pop." << endl;
    }
}

char stack::peek() {
    if (!arr.empty()) {
        return arr.back();
    } else {
        cout << "Stack is empty." << endl;
        return '\0'; // return null character if stack is empty
    }
}

void stack::display() {
    if (arr.empty()) {
        cout << "Stack is empty." << endl;
    } else {
        for (char ch : arr) {
            cout << ch << " ";
        }
        cout << endl;
    }
}
