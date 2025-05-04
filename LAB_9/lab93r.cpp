//Program to implement a tree ADT using a binary search tree
#include<iostream>
using namespace std;

class BST {

    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        }
    };

    public:

    Node* root;
    BST() {
       root = NULL;
    }

    Node* insert(Node* root, int val) {
        if (root == NULL) {
            return new Node(val);
        } 
        if (val < root->data) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }

        return root;
    } 

    void insert(int val);
    
    void inorder(Node* root);

    void inorder();

    void preorder(Node* root);

    void preorder();

    void postorder(Node* root);

    void postorder();

    bool search(Node* root,int val);

    bool search(int val);
};

int main() {
    BST tree;
    int choice;
    int value;

    do {
       cout << "\n TREE ADT MENU:";
       cout << "\n 1. Insert number \n 2. Preorder \n 3. Inorder \n 4. Postorder \n 5. Search \n 6. Exit \n" << endl;
       cout << "Enter your choice: ";
       cin >> choice;

       switch (choice) {
                case 1:  //insertion 
                    cout << "Enter the number you want to insert: ";
                    cin >> value;
                    tree.insert(value);
                    break;


                case 2:   //Preorder traversal
                    cout << "The preorder traversal is as follows: ";
                    tree.preorder();
                    break;


                case 3:  //Inorder traversal
                    cout << "The inoder traversal is given as follows: ";
                    tree.inorder();
                    break;

                
                case 4:  //postorder traversal 
                    cout << "The postorder traversal is as follows: ";
                    tree.postorder();
                    break;


                case 5:  //search 
                    cout << "Enter the value you want to search: ";
                    cin >> value;
                    if( tree.search(value)) {
                        cout << "The element is found in the tree." << endl;
                    } else {
                        cout << "The element is not found in the tree" << endl;
                    }
                    break;


                case 6:
                    cout << "Exciting the program...." << endl;
                    break;
  
            }
    } while(choice != 6);

    return 0;
}

//Function definitions 
    
void BST::insert(int val) {
    root = insert(root,val);
 }

void BST::inorder(Node* root) {
        if (root) {
            inorder(root->left);
            cout << root->data <<" ";
            inorder(root->right);
        }
    }

void BST::inorder() {
    inorder(root);
}

void BST::preorder(Node* root) {
        if (root) {

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);

        }
    }

void BST::preorder() {
    preorder(root);
}

void BST::postorder(Node* root){
        if (root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
    }
}

void BST::postorder() {
    postorder(root);
}

bool BST::search(Node* root, int val){
    if (root == NULL){
        return false;
    }
    if (root->data == val){
        return true;
    }

    return (val < root->data) ? search(root->left ,val) : search(root->right, val);

}

bool BST::search(int val){
     return search(root,val);
}