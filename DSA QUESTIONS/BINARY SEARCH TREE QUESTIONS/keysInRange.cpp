#include<iostream>
#include<vector>
using namespace std;

// Node class for Binary Search Tree
class Node {
public:
    int data;        // Value stored in the node
    Node* left;      // Pointer to left child
    Node* right;     // Pointer to right child

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

// Find all values in BST that lie within the given range [st, end]
void inRange(Node* root, int st, int end, vector<int>& ans) {
    if (root == NULL) return;

    if (st <= root->data && root->data <= end) {
        // Current node is within range:
        // 1. Recursively check left subtree
        inRange(root->left, st, end, ans);
        // 2. Add current node's value
        ans.push_back(root->data);
        // 3. Recursively check right subtree
        inRange(root->right, st, end, ans);
    }
    else if (st > root->data) {
        // If start range is greater than current node,
        // only check right subtree as left will be smaller
        inRange(root->right, st, end, ans);
    }
    else {
        // If end range is smaller than current node,
        // only check left subtree as right will be larger
        inRange(root->left, st, end, ans);
    }
}

int main() {
    // Initialize values to build BST
    vector<int> nodes = { 8, 5, 3, 1, 4, 6, 10, 11, 14 };

    // Build the Binary Search Tree
    Node* root = buildBST(nodes);

    // Print tree values in sorted order
    cout << "Full BST in sorted order: ";
    inorder(root);
    cout << endl;

    // Find and print all values between 5 and 12
    vector<int> ans;
    inRange(root, 5, 12, ans);

    cout << "Values in range [5, 12]: ";
    for (int item : ans) {
        cout << item << " ";
    }

    return 0;
}