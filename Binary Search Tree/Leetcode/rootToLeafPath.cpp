#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Node class for a Binary Search Tree (BST).
class Node {
public:
    int data;        // Value stored in the node
    Node* left;      // Pointer to left child (smaller values)
    Node* right;     // Pointer to right child (larger values)

    // Constructor: create a new node with given value
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Insert a value into the BST.
Node* insert(Node* root, int val) {
    if (root == NULL) {
        // Empty spot found: create and return new node
        root = new Node(val);
        return root;
    }

    // Recurse left or right depending on value
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);

    return root;
}

// Build BST from a vector of integers (in insertion order).
Node* buildBST(vector<int>& nodes) {
    Node* root = NULL;
    for (int i = 0; i < nodes.size(); i++) {
        root = insert(root, nodes[i]);
    }
    return root;
}

// Inorder traversal: prints node values in sorted order for a BST.
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Collect root-to-leaf paths and store them as strings.
void paths(Node* root, string& path, vector<string>& ans) {
    if (root == NULL) return;

    // remember length before adding this node
    int prev = path.size();

    // if path not empty add separator
    if (!path.empty()) path += "->";
    
    path += to_string(root->data);

    // if leaf, record the path
    if (!root->left && !root->right) {
        ans.push_back(path);
    }
    else {
        // otherwise continue down the tree
        paths(root->left, path, ans);
        paths(root->right, path, ans);
    }

    // restore path to its previous state
    path.resize(prev);
}

int main() {
    // Example input values (insertion order)
    vector<int> nodes = { 8, 5, 3, 1, 4, 6, 11, 10, 12, 14 };

    // Build the BST
    Node* root = buildBST(nodes);

    // Print the BST in sorted order (inorder traversal)
    cout << "Full BST in sorted order: ";
    inorder(root);
    cout << endl;

    // Collect and print root-to-leaf paths
    vector<string> ans;
    string path;
    paths(root, path, ans);

    for (string items : ans) {
        cout << items << endl;
    }

    return 0;
}