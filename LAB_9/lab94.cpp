//Program to construct an expresion tree using binary tree 
#include<iostream>
#include<stack>
using namespace std;

class expressiontree {
    struct Node {
        char data;
        Node* left;
        Node* right;


        Node(char val) {
            data = val;
            left = NULL;
            right = NULL;
        }
     };

    Node* root;

    public:
   

    expressiontree() {
            root = NULL;
     }

    Node* constructtree( string postfix) {
           stack<Node*> st;
           for( char ch : postfix) {
            if(isalnum(ch)) {
                st.push(new Node(ch));
            } else {
                Node* node = new Node(ch);
                node->right = st.top();
                st.pop();
                node->left = st.top();
                st.pop();
                st.push(node);
            }
           }
           root = st.top();
           return root;
     }
    
    void preorder(Node* root) {
        if (root) {
            cout << root->data <<"";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void preorder() {
        preorder(root);
    }

    void inorder(Node* root) {
        if (root) {
            if (!isalnum(root->data))
            cout << "(" ;
            inorder(root->left);
            cout << root->data << "";
            inorder(root->right);
            if(!isalnum(root->data));
            cout << ")";
        }
    }

    void inorder() {
        inorder(root);
    }
  
    void postorder(Node* root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << "";
        }
    }

    void postorder() {
        postorder(root);
    }

};

int main() {
    expressiontree tree;
    string postfix;
    int choice;

    do {
        cout << "\n MENU FOR EXPRESSION TREE:" ;
        cout << "\n 1. Enter Postfix Expression \n 2. Construct EXpression Tree \n 3. Preorder Expression \n 4. Inorder Expression \n 5. Postorder Expression \n 6. Exit" << endl;
        cout << "Enter your choice: " ;
        cin >> choice;

        switch (choice) {
                    case 1:   //get the postfic expression from the user
                        cout << "Enter the postfix expression: ";
                        cin >> postfix;
                        break;

                    case 2:  //construct the expressin tree 
                        tree.constructtree(postfix);
                        break;

                    case 3:  //preporder expression
                        cout << "The prefix or preorder expression is as follow:";
                        tree.preorder();
                        break;

                    case 4:  //inorder expression
                        cout << "The inorder expression is as follows: ";
                        tree.inorder();
                        break;

                    case 5:  //postorder expression 
                        cout << "The postorder expression is as follows: ";
                        tree.postorder();
                        break;

                    case 6:
                        cout << "Exciting the program.." << endl;
                        break;


        }

    }while(choice != 6);

    return 0;
}