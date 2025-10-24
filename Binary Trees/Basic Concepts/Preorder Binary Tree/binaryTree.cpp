/*************************************************************************
 * binaryTree.cpp
 *
 * Simple example to build a binary tree from a preorder list using a
 * sentinel value (-1) to mark NULL children.
 *
 * Representation (preorder input):
 *   { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 }
 *
 * Visual (binary tree):
 *
 *         1
 *        / \
 *       2   3
 *      / \   \
 *     4   5   6
 *
 * Notes:
 * - The input vector is interpreted as a preorder traversal where -1
 *   indicates a null child.
 * - The function buildTree consumes entries from the vector using a
 *   global index. For safety a bounds check is performed.
 *************************************************************************/

#include <iostream>
#include <vector>
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

// Global index used by buildTree to traverse the input vector.
static int idx = -1;

Node* buildTree(const vector<int>& nodes) {
    idx++;

    // Bounds check: if idx is beyond the list, return NULL.
    if (idx >= static_cast<int>(nodes.size()) || nodes[idx] == -1) {
        return NULL;
    }

    // Create the current node and recursively build left and right
    // subtrees in preorder.
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

int main() {
    // Preorder representation; -1 marks a NULL child
    vector<int> nodes = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };

    // Reset the global index before building the tree (important if
    // buildTree is called multiple times during program lifetime).
    idx = -1;

    Node* root = buildTree(nodes);
    cout << "root: " << root->data << endl;
   
    return 0;
}