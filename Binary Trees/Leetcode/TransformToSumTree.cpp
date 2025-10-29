#include<iostream>
#include<vector>
using namespace std;

/**
 * Node class represents a binary tree node
 * Each node contains:
 * - data: integer value stored in the node
 * - left: pointer to left child
 * - right: pointer to right child
 */
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor initializes node with given data and NULL children
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Global index for tracking position while building tree from preorder array
static int idx = -1;

/**
 * Builds a binary tree from a preorder traversal array
 * @param nodes Vector containing preorder traversal with -1 marking NULL nodes
 * @return Root node of the constructed binary tree
 */
Node* buildTree(vector<int>& nodes) {
    idx++;

    // Return NULL if we reach end of array or encounter -1
    if (idx >= static_cast<int>(nodes.size()) || nodes[idx] == -1) return NULL;

    // Create new node and recursively build left and right subtrees
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

/**
 * Transforms binary tree to sum tree where each node's value becomes
 * sum of its children's values plus sum of all values in left and right subtrees
 * @param root Root node of the binary tree
 * @return Original value of the current node (before transformation)
 */
int transform(Node* root) {
    if (root == NULL) return 0;

    // Store old values before transformation
    int leftOld = transform(root->left);   // Process left subtree
    int rightOld = transform(root->right); // Process right subtree
    int currOld = root->data;             // Save current node's original value

    // Transform current node to sum of children and their subtrees
    root->data = leftOld + rightOld;  // Add old values from subtrees
    if (root->left) root->data += root->left->data;   // Add left child's new value
    if (root->right) root->data += root->right->data; // Add right child's new value

    return currOld; // Return original value for parent's calculation
}

/**
 * Performs preorder traversal of the binary tree (Root -> Left -> Right)
 * @param root Root node of the binary tree
 */
void traversal(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";     // Print current node
    traversal(root->left);         // Visit left subtree
    traversal(root->right);        // Visit right subtree
}

int main() {
    // Create a sample binary tree using preorder representation
    // -1 indicates NULL child in the sequence
    vector<int> nodes = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };

    // Build the tree, transform it to sum tree, and display the result
    Node* root = buildTree(nodes);
    transform(root);               // Convert to sum tree
    traversal(root);              // Print the transformed tree
    return 0;
}