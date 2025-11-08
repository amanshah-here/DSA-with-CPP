#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Node class for a Binary Search Tree (BST).
class Node {
public:
    int data;        // Value stored in the node
    Node* left;      // Pointer to left child (smaller values)
    Node* right;     // Pointer to right child (larger values)

    // Constructor: create a new node with given value
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Convert a sorted array to a balanced Binary Search Tree
Node* arrayToBST(vector<int>& nodes, int st, int end) {
    // Base case: invalid range
    if (st > end) return NULL;

    // Find middle element - will be the root of current subtree
    int mid = st + (end - st) / 2;

    // Create new node with middle element
    Node* curr = new Node(nodes[mid]);
    // Recursively build left and right subtrees
    curr->left = arrayToBST(nodes, st, mid - 1);
    curr->right = arrayToBST(nodes, mid + 1, end);

    return curr;
}

// preorder traversal: prints node values in order: root ->  left subtree -> right subtree
void preorder(Node* root) {
    // Base case: empty subtree
    if (root == NULL) return;

    cout << root->data << " ";   // Print current node's value
    preorder(root->left);        // Visit left subtree
    preorder(root->right);       // Visit right subtree
}

int main() {
    // Create a sorted array of numbers
    vector<int> nodes = { 3, 4, 5, 6 , 7, 8, 9 };

    // Convert sorted array to a balanced BST
    Node* root = arrayToBST(nodes, 0, nodes.size() - 1);

    // Print the BST using inorder traversal
    cout << "Full BST in sorted order: ";
    preorder(root);
    cout << endl;

    return 0;
}