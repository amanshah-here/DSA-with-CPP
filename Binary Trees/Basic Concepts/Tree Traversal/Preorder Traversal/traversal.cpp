#include<iostream>
#include<vector>
using namespace std;

// Simple binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Index used when building the tree from a vector (preorder sequence)
static  int idx = -1;

// Build a binary tree from a preorder list where -1 marks a NULL node
Node* buildTree(vector<int> nodes) {
    idx++;
    if (nodes[idx] == -1) return NULL;

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

// Preorder traversal (root -> left -> right)
// Prints -1 for NULL nodes to match the input sentinel
void preOrder(Node* root) { // O(N)
    if (root == NULL) {
        cout << "-1 ";
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    // Example preorder representation with -1 as null marker
    vector<int> nodes = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };

    Node* root = buildTree(nodes);
    cout << "root: " << root->data << endl;

    /*
    *         1
    *        / \
    *       2   3
    *      / \   \
    *     4   5   6
    */
    preOrder(root);
    return 0;
}