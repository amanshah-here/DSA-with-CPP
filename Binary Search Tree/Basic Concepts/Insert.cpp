#include<iostream>
#include<vector>
using namespace std;

// Node class represents a node in Binary Search Tree
class Node {
public:
    int data;      // Value stored in the node
    Node* left;    // Pointer to left child
    Node* right;   // Pointer to right child

    // Constructor to initialize a new node
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Function to insert a new value into BST - Time Complexity: O(log n)
Node* insert(Node* root, int val) {
    // If tree is empty, create a new node as root
    if (root == NULL) {
        root = new Node(val);
        return root;
    }

    // Recursively insert nodes - left if value is smaller, right if larger
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);

    return root;
}

// Function to build BST from array of values
Node* buildBST(vector<int>& nodes) {
    Node* root = NULL;

    // Insert each value into BST
    for (int i = 0; i < nodes.size(); i++) {
        root = insert(root, nodes[i]);
    }

    return root;
}

// Function to print BST in inorder traversal (sorted order)
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);     // Visit left subtree
    cout << root->data << " ";  // Print current node
    inorder(root->right);    // Visit right subtree
}

int main() {
    // Sample array to create BST
    vector<int> nodes = { 5, 1, 3, 4, 2, 7 };

    // Build the BST
    Node* root = buildBST(nodes);

    // Print tree in sorted order
    inorder(root);

    return 0;
}