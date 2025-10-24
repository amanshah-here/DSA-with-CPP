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

// Global index used by buildTree to consume the input vector sequentially.
static int idx = -1;

// buildTree: recursively builds the binary tree from the vector 'nodes'.
// It increments 'idx' each call; when nodes[idx] == -1 we return NULL.
Node* buildTree(vector<int> nodes) {
    idx++;
    if (nodes[idx] == -1) return NULL;

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

// Recursive post-order traversal: traverse left, then right, then visit root.
// Time complexity: O(N), where N is the number of nodes.
void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    // nodes vector uses -1 to represent NULL children; matches the visual above.
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
    postOrder(root);
    return 0;
}