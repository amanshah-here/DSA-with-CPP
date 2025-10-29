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

int kthAncestor(Node* root, int n, int k) { //O(n)
    if (root == NULL) return -1;
    if (root->data == n) return 0;

    int left = kthAncestor(root->left, n, k);
    int right = kthAncestor(root->right, n, k);

    if (left == -1 && right == -1) return -1;
    int valid = left == -1 ? right : left;

    if (valid + 1 == k) cout<<"kth ancestor: "<<root->data;

    return valid + 1;
}

int main() {
    // example preorder vector, where -1 denotes a NULL child
    vector<int> nodes = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };

    // build tree and print 2nd Ancestor of node 5.
    Node* root = buildTree(nodes);
    cout << "Kth Ancestor: " << kthAncestor(root, 5, 1) << endl;
    return 0;
}