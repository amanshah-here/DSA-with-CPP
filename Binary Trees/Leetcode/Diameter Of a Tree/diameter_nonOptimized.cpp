#include<iostream>
#include<vector>
using namespace std;

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

static int idx = -1;

Node* buildTree(vector<int>& nodes) {
    idx++;

    if (idx >= static_cast<int> (nodes.size()) || nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

int maxDepth(Node* root) {
    if (root == NULL) return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return max(leftDepth, rightDepth) + 1;
}

int diameter(Node* root) {  //* O(n^2)
    if (root == NULL) return 0;

    int currDiameter = maxDepth(root->left) + maxDepth(root->right) + 1;    //*  O(n)

    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    return max(currDiameter, max(leftDiameter, rightDiameter));
}
int main() {
    vector<int> nodes = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };
    Node* root = buildTree(nodes);

    cout << "Diameter of the tree: " << diameter(root);

    return 0;
}