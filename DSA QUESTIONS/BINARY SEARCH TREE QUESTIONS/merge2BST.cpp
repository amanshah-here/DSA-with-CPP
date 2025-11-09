#include<iostream>
#include<vector>
using namespace std;

// Node class for Binary Search Tree
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

// Convert BST to sorted array using inorder traversal
void getSorted(Node* root, vector<int>& nodes) {
    if (root == NULL) return;

    getSorted(root->left, nodes);      // Process left subtree
    nodes.push_back(root->data);       // Add current node
    getSorted(root->right, nodes);     // Process right subtree
}

// Merge two sorted arrays into one sorted array
vector<int> merge(vector<int>& BST1, vector<int>& BST2) {
    int i = 0, j = 0;
    vector<int> temp;
    // Compare and merge elements from both arrays
    while (i < BST1.size() && j < BST1.size()) {
        if (BST1[i] < BST2[j]) {
            temp.push_back(BST1[i++]);
        }
        else {
            temp.push_back(BST2[j++]);
        }
    }

    while (i < BST1.size()) {
        temp.push_back(BST1[i++]);
    }
    while (j < BST2.size()) {
        temp.push_back(BST2[j++]);
    }
   
    return temp;
}

// Convert sorted array to balanced BST
Node* ArraytoBST(vector<int>& nodes, int st, int end) {
    if (st > end) return NULL;

    // Find middle element to make root
    int mid = st + (end - st) / 2;

    Node* currNode = new Node(nodes[mid]);

    currNode->left = ArraytoBST(nodes, st, mid - 1);
    currNode->right = ArraytoBST(nodes, mid + 1, end);

    return currNode;
}

// Main function to merge two Binary Search Trees
Node* merger2BST(Node* root1, Node* root2) {
    // Convert first BST to sorted array
    vector<int> BST1;
    getSorted(root1, BST1);

    vector<int> BST2;
    getSorted(root2, BST2);

    vector<int> merged = merge(BST1, BST2);
    return ArraytoBST(merged, 0, merged.size() - 1);
}

// Print BST using inorder traversal
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);              // Process left subtree
    cout << root->data << "->";       // Print current node
    inorder(root->right);             // Process right subtree
}

int main() {
    // Create first BST: [2,1,4]
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    // Create second BST: [9,3,12]
    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    inorder(root1);
    cout << endl;
    inorder(root2);
    cout << endl;

    Node* root = merger2BST(root1, root2);
    inorder(root);

    return 0;
}