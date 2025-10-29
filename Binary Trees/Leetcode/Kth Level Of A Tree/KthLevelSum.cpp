#include<iostream>
#include<vector>
using namespace std;

// Basic binary tree node
// Holds an integer and left/right child pointers
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

// index used to build tree from preorder-like array representation
// This is a small global index advanced while building the tree
static int idx = -1;

Node* buildTree(vector<int>& nodes) {
    idx++;
    // If out of range or marker (-1) found, return NULL
    // Note: -1 in the vector represents a NULL child
    if (idx > static_cast<int>(nodes.size()) || nodes[idx] == -1) return NULL;

    // create current node and recursively build left/right
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
}
// DFS helper: traverse tree and collect nodes at level K
// currLevel is current node's level (root = 1)
void KthHelper(Node* root, int K, int currLevel, int& sum) {    // O(n)
    if (root == NULL) return;
    if (currLevel == K) {
        sum += root->data; // collect value 
    }

    // recurse to children increasing level
    KthHelper(root->left, K, currLevel + 1, sum);
    KthHelper(root->right, K, currLevel + 1, sum);
}
int KthLevelSum(Node* root, int K) {
    int sum = 0;
    KthHelper(root, K, 1, sum); // start levels at 1 for the root

    return sum;
}

int main() {
    // Example tree encoded as preorder with -1 markers for NULL
    // This vector represents: 1 -> 2,3  and so on
    vector<int> nodes = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };

    Node* root = buildTree(nodes); // build the tree
    cout << "sum:" << KthLevelSum(root, 2) << endl; // print sum at level 2

    return 0;
}