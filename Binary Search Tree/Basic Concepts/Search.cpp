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

// Search for a key in BST - Time complexity: O(log n)
Node* search(Node* root, int key) {
    // If tree is empty or key not found at leaf node
    if (root == NULL) {
        cout << "Not Found\n";
        return NULL;
    }

    // Key found at current node    
    if (root->data == key) {
        cout << "Found\n";
        return root;
    }

    // Recursively search left or right subtree based on key value
    if (root->data > key) {
        return search(root->left, key);
    }

    else {
        return search(root->right, key);
    }
}

// Inorder traversal of BST (prints values in sorted order)
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);      // Visit left subtree
    cout << root->data << " "; // Print current node
    inorder(root->right);     // Visit right subtree
}

int main() {
    // Initialize values to build BST
    vector<int> nodes = { 8, 5, 3, 1, 4, 6, 10, 11, 14 };

    // Build the Binary Search Tree
    Node* root = buildBST(nodes);

    // Print tree values in sorted order
    inorder(root);
    cout << endl;

    // Search for value 4 in the tree
    Node* node = search(root, 4);
    cout << node << " "; // Print the address of found node

    return 0;
}