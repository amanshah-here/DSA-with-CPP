#include<iostream>
#include<vector>
using namespace std;

// Binary Tree Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize node with data and NULL children
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Global index for tree construction
static int idx = -1;

// Builds binary tree from array representation (-1 represents NULL)
Node* buildTree(vector<int>& nodes) {
    idx++;

    // Base case: return NULL if index out of bounds or node is -1
    if (idx >= static_cast<int>(nodes.size()) || nodes[idx] == -1) {
        return NULL;
    }

    // Create new node and recursively build left and right subtrees
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

// Checks if two trees are structurally identical
bool isIdentical(Node* root1, Node* root2) {
    // Base cases for NULL nodes
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;
    if (root1->data != root2->data) return false;

    // Recursively check left and right subtrees
    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}

// Checks if subRoot is a subtree of root
bool isSubTree(Node* root, Node* subRoot) {
    // Base cases for NULL nodes
    if (root == NULL && subRoot == NULL) return true;
    if (root == NULL || subRoot == NULL) return false;

    // If current nodes match, check for identical structure
    if (root->data == subRoot->data) {
        if (isIdentical(root, subRoot)) return true;
    }

    // Check in left subtree, if not found, check right subtree
    int isLeft = isSubTree(root->left, subRoot);
    if (!isLeft) {
        return isSubTree(root->right, subRoot);
    }
    return true;
}

int main() {
    // Create main tree: 1(2(4,5),3(-,6))
    vector<int> nodes = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };

    // Build main tree and create subtree to search for
    Node* root = buildTree(nodes);
    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);

    // Check if subRoot is a subtree of root
    cout << isSubTree(root, subRoot);

    return 0;
}