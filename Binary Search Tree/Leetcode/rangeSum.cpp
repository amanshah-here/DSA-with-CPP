#include<iostream>
#include<vector>
using namespace std;

// Node class for Binary Search Tree (BST)
// Each node contains a value and pointers to its left and right children
// In a BST, left child is always smaller and right child is always larger than parent
class Node {
public:
    int data;        // Value stored in the node
    Node* left;      // Pointer to left child (smaller values)
    Node* right;     // Pointer to right child (larger values)

    // Constructor to create a new node
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Insert a new value into BST - Time complexity: O(log n)
Node* insert(Node* root, int val) {
    // If tree is empty, create a new node as root
    if (root == NULL) {
        root = new Node(val);
        return root;
    }

    // Recursively insert to left or right subtree based on value
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);

    return root;
}

// Build BST from a vector of integers
Node* buildBST(vector<int>& nodes) {
    Node* root = NULL;

    // Insert each value from the vector into BST
    for (int i = 0; i < nodes.size(); i++) {
        root = insert(root, nodes[i]);
    }

    return root;
}

// Inorder traversal of BST (prints values in sorted order)
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);      // Visit left subtree
    cout << root->data << " "; // Print current node
    inorder(root->right);     // Visit right subtree
}

// Calculate sum of all nodes with values in range [st, end]
void rangeSum(Node* root, int st, int end, int& ans) {
    if (root == NULL) return;

    if (st <= root->data && root->data <= end) {
        // Current node is within range, add its value and check both subtrees
        ans += root->data;
        rangeSum(root->left, st, end, ans);
        rangeSum(root->right, st, end, ans);
    }  
    else if (st > root->data) {
        // Current value too small, only check right subtree
        rangeSum(root->right, st, end, ans);
    }
    else {
        // Current value too large, only check left subtree
        rangeSum(root->left, st, end, ans);
    }
}

int main() {
    // Initialize values to build BST
    vector<int> nodes = { 8, 5, 3, 1, 4, 6, 10, 11, 14 };

    // Build the Binary Search Tree from the vector
    Node* root = buildBST(nodes);

    // Print tree values in sorted order using inorder traversal
    cout << "Full BST in sorted order: ";
    inorder(root);
    cout << endl;

    // Calculate sum of all values between 5 and 12 (inclusive)
    int sum = 0;
    rangeSum(root, 5, 12, sum);

    // Print the range sum result
    cout << "Sum of values between 5 and 12: " << sum << endl;

    return 0;
}