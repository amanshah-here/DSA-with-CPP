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

// Find lowest common ancestor of n1 and n2 in the tree
Node* LCA(Node* root, int n1, int n2) {
    if (root == NULL) return NULL; // empty subtree


    // if current node is one of the targets, return it
    if (root->data == n1 || root->data == n2) return root;

    // search in left and right subtrees
    Node* leftLca = LCA(root->left, n1, n2);
    Node* isLeftLCA = LCA(root->left, n1, n2);
    Node* isRightLCA = LCA(root->right, n1, n2);

    // if both sides returned non-null, current node is LCA
    if (isLeftLCA != NULL && isRightLCA != NULL) return root;

    // otherwise return the non-null result
    return isLeftLCA == NULL ? isRightLCA : isLeftLCA;
}

// Returns distance from root to node with value n, or -1 if not found
int distance(Node* root, int n) {
    if (root == NULL) return -1;
    if (root->data == n) return 0;

    int left = distance(root->left, n);
    if (left != -1) {
        return left + 1;
    }
    int right = distance(root->right, n);
    if (right != -1) return right + 1;

    return -1;
}

// Calculate minimum distance between two nodes using their LCA
int minDistance(Node* root, int n1, int n2) {
    // Find LCA first, then sum distances from LCA to both nodes
    Node* Lca = LCA(root, n1, n2);

    int dist1 = distance(Lca, n1);
    int dist2 = distance(Lca, n2);

    return dist1 + dist2;
}

int main() {
    // example preorder vector, where -1 denotes a NULL child
    vector<int> nodes = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };

    // build tree and print minimum distance of nodes 4 and 6
    Node* root = buildTree(nodes);
    cout << "Minimum Distance: " << minDistance(root, 4, 6) << endl;
    return 0;
}