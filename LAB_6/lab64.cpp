//Program to check the valid paranthesis

#include<iostream>
#include<vector>
using namespace std;

    int top(vector<char>st){
        return st[st.size() -1];
    }

    bool isvalid(string str){
        vector<char> st;
        for( int i = 0 ; i < str.size() ; i++){
            if(str[i] == '(' || str[i] == '{' || str[i] == '['){
                st.push_back(str[i]);
            }else {
                if( str.size() == 0)
                return false;

            if( (top(st) == '(' && str[i] == ')') || (top(st) == '{' && str[i] == '}') || (top(st) == '[' && str[i] == ']')){
                st.pop_back();
            } else {
                return false;
            }
        
        }
        
    }
        return st.size() == 0;
    
    }

int main(){
    string input ;

    cout << " Enter the paranthesis string: ";
    cin >> input;
    
    if(isvalid(input)) {
     cout << "The string is valid" << endl;
    } else {
     cout << "The string is invalid" << endl;
    }

    return 0;
}  