#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Basic binary tree node (holds integer data and left/right pointers)
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

// Global index used when building the tree from a preorder vector
// The code expects a preorder list where -1 indicates a NULL child
static  int idx = -1;

// Build tree from preorder list using -1 as sentinel for NULL
// Recursively consumes elements from `nodes` using `idx`
Node* buildTree(vector<int> nodes) {
    idx++;
    if (nodes[idx] == -1) return NULL;

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

// Level-order traversal (breadth-first) using a queue
// Time complexity O(N) where N is number of nodes
void levelOrder(Node* root) { // O(N)
    queue<Node*> Q;
    // push root (assumes caller gives a non-null root)
    Q.push(root);

    while (!Q.empty()) {
        Node* currNode = Q.front();
        Q.pop();

        cout << currNode->data << " ";

        if (currNode->left) {
            Q.push(currNode->left);
        }
        if (currNode->right) {
            Q.push(currNode->right);
        }
    }
}

int main() {
    vector<int> nodes = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };

    Node* root = buildTree(nodes);
    cout << "root: " << root->data << endl;

    // print nodes level by level
    levelOrder(root);
    return 0;
}