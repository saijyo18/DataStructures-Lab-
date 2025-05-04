//IMplement the program using stack and getting the required output;
#include<iostream>
#include<stack>
using namespace std;

string processedstring(const string &input){
    stack<char> st;
    for( char ch : input) {
        if ( ch == '+'){
            if(!st.empty()){
                st.pop();
            } 
        } else {
            st.push(ch);
        }
    }

   string result;
   while(!st.empty()){
    result = st.top() + result;
    st.pop();
   } 

   return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    string result;
    result = processedstring(input);
    cout << result << endl;


    return 0;
} 