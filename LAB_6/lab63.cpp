//program to convert inflix to postflix and to evaluate the postflix

#include<iostream>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

class operations {

    public:
    int prec(char ch);
    void infixtopost(string str);
    int postfixev( string str);


};


int main() {
    string str;
    operations opp;
    int choice;

    do {
      cout << "MENU" << endl;
      cout << "1. Get Infix " << endl;
      cout << "2. Convert Postfix " << endl;
      cout << "3. Evaluate Postfix " << endl;
      cout << "4. Exit " << endl;
      cout << "Choose an Option from the above menu: ";
      cin >> choice;

      switch (choice) {
                    case 1:
                     cout << "Enter a string: ";
                     cin >> str;
                     break;
                    
                     case 2:
                     opp.infixtopost(str);
                     break;

                     case 3:
                     opp.postfixev(str);
                     break;

                     case 4:
                     cout << "Exciting the program.." << endl;
                     break;

               }

        } while(choice != 4);

    return 0;

}


void operations::infixtopost(string str){
    string res; // string to store the operand 
    stack<char> st;
    
     for(char ch : str ){
        
        if( ( ch >= 'a' && ch <= 'z') || ( ch >= 'A' && ch <= 'Z') || ( ch >= '0' && ch <= '9'))  //stores the operand in the string 
            res += ch;
        

        else if ( ch == '(') // if paranthesis occurs 
            st.push(ch);
        

        else if ( ch == ')'){
            while( st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop();
        }

       else {
            while(!st.empty() && prec(ch) <= prec(st.top())){     //if any operator is read, then to add itto  the stack
                res += st.top();
                st.pop();
            }
            st.push(ch);

       }
    }

    while ( !st.empty()){  //finally check if the stack is empty
        res += st.top();
        st.pop();
       }
            
     cout << res << endl;
       
}

int operations::prec(char ch){
    if( ch == '^')
    return 3;
    else if( ch == '*' || ch == '/')
     return 2;
    else if( ch == '+' || ch == '-')
     return 1;
    else 
     return -1;
}

int operations::postfixev( string str){
  
    stack<int> st;
  
    for(char ch : str){
      if( ( ch >= '0' && ch <= '9')){
         st.push(ch - '0'); //convert the char to int 
         cout << st.top();
      } 
      else {
          if (st.size()< 2){
              cout  << "Invalid operands are present." << endl;
              return -1;
          }
          int op2 = st.top();
          st.pop();
          int op1 = st.top();
          st.pop();
  
          int res;
  
          switch (ch) {
              case '+': 
                res = op1 + op2;
                break;
              case '-':
                res = op1 - op2;
                break;
              case '/':
                if( op2 ==0){
                  cout << "Division is not possible." << endl;
                  return -1;
                }
              res = op1/op2;
              break;
              case '*':
               res = op1*op2;
               break;
              case '^':
               res = pow(op1, op2);
               break;
  
          }
  
         st.push(res);
      }
   }
  
    if (st.size() != 1) {
      cout << "Error: Invalid expression" << endl;
      return -1;
  }
  
   return st.top();
    
    } 