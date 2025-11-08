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

// Insert a value into the BST.
Node* insert(Node* root, int val) {
    if (root == NULL) {
        // Empty spot found: create and return new node
        root = new Node(val);
        return root;
    }

    // Recurse left or right depending on value
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);

    return root;
}

// Build BST from a vector of integers (in insertion order).
Node* buildBST(vector<int>& nodes) {
    Node* root = NULL;
    for (int i = 0; i < nodes.size(); i++) {
        root = insert(root, nodes[i]);
    }
    return root;
}

// Inorder traversal: prints node values in sorted order for a BST.
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Check if a binary tree is a valid BST
bool isValidBST(Node* root, Node* min, Node* max) {
    // Empty tree is valid
    if (root == NULL) return true;

    // Check if current node's value is within allowed range
    if (min && root->data <= min->data) return false;  // Value too small
    if (max && root->data >= max->data) return false;  // Value too large

    // Recursively check left and right subtrees
    return isValidBST(root->left, min, root)
        && isValidBST(root->right, root, max);
}

int main() {
    // Example input values to create a valid BST
    // The tree will look like:
    //       8
    //     /   \
    //    5     10
    //   / \      \
    //  3   6      11
    // / \          \
    //1   4          14
    vector<int> nodes = { 8, 5, 3, 1, 4, 6, 10, 11, 14 };

    // Build the BST from input values
    Node* root = buildBST(nodes);

    // Print the BST in sorted order (inorder traversal)
    cout << "Full BST in sorted order: ";
    inorder(root);
    cout << endl;

    // Check if the tree is a valid BST and print result (1 for valid, 0 for invalid)
    cout << "Is valid BST? " << isValidBST(root, NULL, NULL) << endl;
    return 0;
}