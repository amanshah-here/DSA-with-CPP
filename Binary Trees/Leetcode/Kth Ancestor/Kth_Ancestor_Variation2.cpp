#include<iostream>
#include<vector>
using namespace std;

// Binary tree node with data and left/right pointers
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

// Index for traversing preorder array while building tree
static int idx = -1;

// Builds tree from preorder array where -1 represents NULL
Node* buildTree(vector<int>& nodes) {
    idx++;

    if (idx >= static_cast<int>(nodes.size()) || nodes[idx] == -1) return NULL;

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

int helper(Node* root, int n, int k, int& ans) { //O(n)
    if (root == NULL) return -1; // Base case: null node
    if (root->data == n) return 0; // Found target node

    int left = helper(root->left, n, k, ans); // Search left
    int right = helper(root->right, n, k, ans); // Search right

    if (left == -1 && right == -1) return -1; // Not found in either subtree
    int validDist = left == -1 ? right : left; // Choose valid path

    if (validDist + 1 == k && ans == -1) ans = root->data; // If kth ancestor, set answer

    return validDist + 1; // Return distance from current node to target
}

int kthAncestor(Node* root, int n, int k) {
    int ans = -1;

    helper(root, n, k, ans);
    return ans;
}

int main() {
    // example preorder vector, where -1 denotes a NULL child
    vector<int> nodes = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };

    // build tree and print 2nd Ancestor of node 5.
    Node* root = buildTree(nodes);
    cout << "Kth Ancestor: " << kthAncestor(root, 6, 1) << endl;
    return 0;
}