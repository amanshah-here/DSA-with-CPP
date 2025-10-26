#include<iostream>
#include<vector>
using namespace std;

// diameter_Optimized.cpp
// Compute the diameter (longest path) of a binary tree in O(n).
// Uses a post-order traversal that returns {diameter, height} for each node.

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

// static index used by buildTree to read values from the input vector
// The vector uses -1 to denote a null node.
static int idx = -1;

Node* buildTree(vector<int>& nodes) {
    idx++;
    // Pre-order reading: root, left subtree, right subtree
    if (idx >= static_cast<int> (nodes.size()) || nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

pair<int, int> diameter(Node* root) {  //* O(n)
    if (root == NULL) return make_pair(0, 0);   //base case

    // returns {diameter, height}
    pair<int, int> leftInfo = diameter(root->left); // {leftDiam, leftHeight}
    pair<int, int> rightInfo = diameter(root->right);   // {rightDiam, rightHeight}

    // diameter passing through current node = leftHeight + rightHeight + 1
    int currDiam = leftInfo.second + rightInfo.second + 1;

    // best diameter so far is max of left, right, or passing-through
    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));

    // Max Height = max(leftHT, rightHT) + 1;
    int height = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDiam, height);
}

int main() {
    vector<int> nodes = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };
    // sample tree represented in pre-order with -1 as null marker
    Node* root = buildTree(nodes);

    // diameter(..).first holds the diameter value
    cout << "Diameter of the tree: " << diameter(root).first;

    return 0;
}