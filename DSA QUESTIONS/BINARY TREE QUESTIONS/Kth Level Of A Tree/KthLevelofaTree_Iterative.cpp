#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Simple binary tree node (stores an int and child pointers)
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

// Global index used by buildTree to walk the input vector in preorder
// The input uses -1 as a sentinel to indicate a NULL child.
static int idx = -1;

// Build tree from a preorder-like representation with -1 = NULL.
// Each call consumes one entry from 'nodes' (advances idx).
Node* buildTree(vector<int>& nodes) {
    idx++;
    if (idx >= static_cast<int>(nodes.size()) || nodes[idx] == -1)
        return NULL; // sentinel or out-of-range -> no node

    Node* currNode = new Node(nodes[idx]);
    // build left and right subtrees recursively
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
}

// Return values at K-th level (1-based). Uses level-order traversal
// with a NULL marker to separate levels. When current level == K,
// store node values into 'ans'.
vector<int> KthLevel(Node* root, int K) {
    vector<int> ans;
    if (root == NULL || K <= 0) return ans;

    queue<Node*> q;
    q.push(root);
    q.push(NULL); // level delimiter
    int currLevel = 1;

    while (!q.empty()) {
        Node* currNode = q.front();
        q.pop();

        if (currNode == NULL) {
            // finished a level
            currLevel++;
            if (q.empty()) break; // no more nodes
            q.push(NULL); // mark end of next level
            continue;
        }

        if (currLevel == K) {
            ans.push_back(currNode->data); // collect values at level K
        }

        if (currNode->left) q.push(currNode->left);
        if (currNode->right) q.push(currNode->right);
    }

    return ans;
}

int main() {
    // Preorder-like encoding: -1 denotes a NULL child.
    // Example represents a small tree; adjust to test other shapes.
    vector<int> nodes = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };

    Node* root = buildTree(nodes);            // construct tree
    vector<int> ans = KthLevel(root, 3);     // get nodes at level 3

    for (int v : ans) cout << v << " ";
    return 0;
}