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

// Perform inorder traversal to get nodes in sorted order
// Stores the values in the 'sorted' vector
void getSorted(Node* root, vector<int>& sorted) {
    if (root == NULL) return;

    getSorted(root->left, sorted);        // Visit left subtree
    sorted.push_back(root->data);         // Add current node's value
    getSorted(root->right, sorted);       // Visit right subtree
}

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

// Main function to convert unbalanced BST to balanced BST
// 1. Get sorted array using inorder traversal
// 2. Build balanced BST from sorted array
Node* BSTtoBalancedBST(Node* root) {
    vector<int> sorted;
    getSorted(root, sorted);              // Get nodes in sorted order

    return arrayToBST(sorted, 0, sorted.size() - 1);  // Create balanced BST
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
    // Create an unbalanced BST as test input
    // The tree is skewed, with nodes: 6->5->4->3 on left
    // and 7->8->9 on right
    Node* root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);

    preorder(root);
    cout << endl;

    root = BSTtoBalancedBST(root);

    preorder(root);

    return 0;
}