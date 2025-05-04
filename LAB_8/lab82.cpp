#include <iostream>
using namespace std;

class Tree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };
    Node* root;

public:
    Tree() { root = nullptr; }

    // Proper BST Insert Function
    void insert(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};

        if (!root) {
            root = newNode;
            return;
        }

        Node* temp = root;
        Node* parent = nullptr;

        while (temp) {
            parent = temp;
            if (value < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }

        if (value < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    // Inorder Traversal (Left, Root, Right) - Correct Order
    void inorder_traversal(Node* node) {
        if (!node) return;
        inorder_traversal(node->left);
        cout << node->data << " ";
        inorder_traversal(node->right);
    }

    void inorder() {
        inorder_traversal(root);
        cout << endl;
    }

    // Preorder Traversal (Root, Left, Right)
    void preorder_traversal(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder_traversal(node->left);
        preorder_traversal(node->right);
    }

    void preorder() {
        preorder_traversal(root);
        cout << endl;
    }

    // Postorder Traversal (Left, Right, Root)
    void postorder_traversal(Node* node) {
        if (!node) return;
        postorder_traversal(node->left);
        postorder_traversal(node->right);
        cout << node->data << " ";
    }

    void postorder() {
        postorder_traversal(root);
        cout << endl;
    }

    // Search Function for BST
    bool search(int key) {
        Node* temp = root;
        while (temp) {
            if (temp->data == key)
                return true;
            temp = (key < temp->data) ? temp->left : temp->right;
        }
        return false;
    }
};

int main() {
    Tree T;
    int choice, value;

    while (true) {
        cout << "\n------- MENU -------\n";
        cout << "1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter integer to insert: ";
                cin >> value;
                T.insert(value);
                break;
            case 2:
                cout << "Preorder Traversal: ";
                T.preorder();
                break;
            case 3:
                cout << "Inorder Traversal: ";
                T.inorder();
                break;
            case 4:
                cout << "Postorder Traversal: ";
                T.postorder();
                break;
            case 5:
                cout << "Enter integer to search: ";
                cin >> value;
                if (T.search(value))
                    cout << value << " found in the tree.\n";
                else
                    cout << value << " not found in the tree.\n";
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
