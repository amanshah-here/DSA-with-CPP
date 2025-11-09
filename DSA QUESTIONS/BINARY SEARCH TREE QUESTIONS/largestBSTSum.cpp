#include <iostream>
#include <vector>
using namespace std;

// Class to represent a node in a binary tree
// Each node contains a value and pointers to its left and right children
class Node {
public:
    int data;        // Value stored in the node
    Node* left;      // Pointer to left child
    Node* right;     // Pointer to right child

    // Constructor: Creates a new node with given value and NULL children
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Helper class to store information about each subtree during traversal
// This info helps determine if a subtree is a valid BST and track its properties
class Info {
public:
    bool isBST;      // True if the subtree is a valid Binary Search Tree
    int min;         // Minimum value in the subtree
    int max;         // Maximum value in the subtree
    int sum;         // Sum of all node values in the subtree

    // Constructor: Initializes a new Info object with given properties
    Info(bool isBST, int min, int max, int sum) {
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->sum = sum;
    }
};

// Global variable to track the maximum sum found in any valid BST
static int maxSum;

// Recursive function to find the largest BST (Binary Search Tree) in a binary tree
Info* largestBST(Node* root) {
    // Base case: NULL tree is considered a valid BST with zero sum
    if (root == NULL)
        return new Info(true, INT8_MAX, INT8_MIN, 0);

    // Step 1: Recursively process left and right subtrees
    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);

    // Step 2: Calculate properties for current subtree
    int currMin = min(root->data, min(leftInfo->min, rightInfo->min));  // Minimum value in current subtree
    int currMax = max(root->data, max(leftInfo->max, rightInfo->max));  // Maximum value in current subtree
    int currSum = leftInfo->sum + rightInfo->sum + root->data;          // Sum of all nodes in current subtree


    // Step 3: Check if current subtree forms a valid BST
    // Conditions for a valid BST:
    // 1. Both left and right subtrees must be BSTs
    // 2. Current node's value must be greater than max value in left subtree
    // 3. Current node's value must be less than min value in right subtree
    if (leftInfo->isBST && rightInfo->isBST
        && root->data > leftInfo->max
        && root->data < rightInfo->min) {

        maxSum = max(maxSum, currSum);  // Update global maximum sum if current BST has larger sum
        return new Info(true, currMin, currMax, currSum);  // Return info for a valid BST
    }

    // If any BST condition fails, return info marking this subtree as invalid BST
    return new Info(false, currMin, currMax, currSum);
}

int main() {
    // Create a sample binary tree for testing
    // The tree structure is:
    //        50
    //      /    \
    //     30    60
    //    /  \   /  \
    //   5   20 45  70
    //              /  \
    //            65   80
    // Note: The right subtree (60 and its descendants) forms the largest BST
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
    cout << "Maximum sum: " << maxSum << endl;

    return 0;
}