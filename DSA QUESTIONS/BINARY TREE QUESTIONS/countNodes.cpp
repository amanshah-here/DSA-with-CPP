#include<iostream>
#include<vector>
using namespace std;

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

static  int idx = -1;

// buildTree: constructs the binary tree from a preorder-encoded vector
// nodes: preorder list where -1 indicates a NULL child. Uses static idx
// to maintain the current read position while recursing.
Node* buildTree(vector<int> nodes) {
    idx++;
    if (nodes[idx] == -1) return NULL;

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

int countNodes(Node* root) {
    if (root == NULL) return 0; // base case

    int leftNodes = countNodes(root->left); // recursive call for left subtree
    int rightNodes = countNodes(root->right); // recursive call for right subtree.

    return leftNodes + rightNodes + 1; // return total nodes (left + right + root)
}

int main() {
    // Preorder vector with -1 as null markers (matches the visual above)
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

    cout << "Total Nodes in the tree: " << countNodes(root) << endl;
    return 0;
}