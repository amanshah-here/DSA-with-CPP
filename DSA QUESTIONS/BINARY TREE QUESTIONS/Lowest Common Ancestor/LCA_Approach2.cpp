#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

// Binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// index used while building tree from preorder vector
static int idx = -1;

Node* buildTree(vector<int>& nodes) {
    // advance to next element in preorder list
    idx++;
    // -1 denotes a NULL child (marker) or stop if out of range
    if (idx > static_cast<int>(nodes.size()) || nodes[idx] == -1) return NULL;

    // create current node and recursively build left/right
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
}

// Find lowest common ancestor of n1 and n2 in the tree
Node* LCA(Node* root, int n1, int n2) {
    if (root == NULL) return NULL;                  // empty subtree

    // if current node is one of the targets, return it
    if (root->data == n1 || root->data == n2) return root;

    // search in left and right subtrees
    Node* leftLca = LCA(root->left, n1, n2);
    Node* rightLca = LCA(root->right, n1, n2);

    // if both sides returned non-null, current node is LCA
    if (leftLca != NULL && rightLca != NULL) return root;

    // otherwise return the non-null result
    return leftLca == NULL ? rightLca : leftLca;
}

int main() {
    // example preorder vector, where -1 denotes a NULL child
    vector<int> nodes = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };

    // build tree and print LCA of nodes 4 and 5
    Node* root = buildTree(nodes);
    cout << "LCA: " << LCA(root, 4, 5)->data;
    return 0;
}