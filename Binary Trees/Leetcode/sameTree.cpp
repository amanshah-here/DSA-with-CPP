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

bool isSameTree(Node* a, Node* b) {
    if (a == NULL && b == NULL) return true; // if both is null means they are same

    if (a == NULL || b == NULL) return false; // if only one of them is null means they are not same

    if (a->data != b->data) return false; // if the values of both trees are different means they are not same

    return isSameTree(a->left, b->left) && isSameTree(a->right, b->right); //recursive call for left and right subtree
}

int main() {
    // Preorder vector with -1 as null markers (matches the visual above)
    vector<int> nodes = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };
    vector<int> nodes2 = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };

    Node* root1 = buildTree(nodes);
    cout << "root: " << root1->data << endl;

    Node* root2 = buildTree(nodes);
    cout << "root: " << root2->data << endl;
    
    /*
    *         1
    *        / \
    *       2   3
    *      / \   \
    *     4   5   6
    */

    cout << isSameTree(root1, root2) << endl;
    return 0;
}