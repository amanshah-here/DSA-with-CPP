#include<iostream>
#include<vector>
using namespace std;

// Visual representation of the tree constructed by the `nodes` vector below:
//
//         1
//        / \
//       2   3
//      / \   \
//     4   5   6
//
// The `nodes` vector is a preorder encoding where -1 represents a NULL child.
// buildTree consumes the vector in preorder using the static `idx` index.

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

//* helper function to traverse the tree and store elements in a vector.
void helper(Node* root, vector<int>& ans) {
    if (root == NULL) return; // base case

    helper(root->left, ans); // recursive call for left subtree

    ans.push_back(root->data); // storing the root value.

    helper(root->right, ans); // recursive call for the right subtree.
}

vector<int> inOrder(Node* root) { // O(N) - inorder traversal: left, root, right
    vector<int> ans;

    helper(root, ans);

    return ans;
}

int main() {
    // Preorder vector with -1 as null markers (matches the visual above)
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

    vector<int> ans = inOrder(root);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}