#include <iostream>
#include <vector>
using namespace std;

// Node class represents a node in binary tree
class Node {
public:
    int data;        // Value stored in the node
    Node* left;      // Pointer to left child
    Node* right;     // Pointer to right child

    // Constructor to create a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Info class stores information about a subtree
class Info {
public:
    bool isBST;      // Whether the subtree is a valid BST
    int min;         // Minimum value in the subtree
    int max;         // Maximum value in the subtree
    int size;        // Number of nodes in the subtree

    // Constructor to initialize subtree information
    Info(bool isBST, int min, int max, int size) {
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->size = size;
    }
};

// Global variable to store the size of largest BST found
static int maxSize;

// Function to find the largest BST in a binary tree
Info* largestBST(Node* root) {
    // Base case: empty tree is a valid BST
    if (root == NULL)
        return new Info(true, INT8_MAX, INT8_MIN, 0);

    // Recursively get information from left and right subtrees
    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);

    // Calculate current subtree's properties
    int currMin = min(root->data, min(leftInfo->min, rightInfo->min));  // Find minimum value
    int currMax = max(root->data, max(leftInfo->max, rightInfo->max));  // Find maximum value
    int currSize = leftInfo->size + rightInfo->size + 1;                // Calculate total nodes


    // Check if current subtree is a valid BST:
    // 1. Both left and right subtrees must be BSTs
    // 2. Current node's value must be greater than max value in left subtree
    // 3. Current node's value must be less than min value in right subtree
    if (leftInfo->isBST && rightInfo->isBST
        && root->data > leftInfo->max
        && root->data < rightInfo->min) {

        maxSize = max(maxSize, currSize);  // Update largest BST size if needed
        return new Info(true, currMin, currMax, currSize);  // Current subtree is a valid BST
    }

    // Current subtree is not a valid BST
    return new Info(false, currMin, currMax, currSize);
}

int main() {
    // Create a sample binary tree
    //        50
    //      /    \
    //     30    60
    //    /  \   /  \
    //   5   20 45  70
    //              /  \
    //            65   80
    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    largestBST(root);
    cout << "Maximum Size: " << maxSize << endl;

    return 0;
}