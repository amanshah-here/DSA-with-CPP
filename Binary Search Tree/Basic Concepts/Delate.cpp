#include<iostream>
#include<vector>
using namespace std;

// Node class represents a node in Binary Search Tree
class Node {
public:
    int data;      // Value stored in the node
    Node* left;    // Pointer to left child
    Node* right;   // Pointer to right child

    // Constructor to initialize a new node
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Function to insert a new value into BST - Time Complexity: O(log n)
Node* insert(Node* root, int val) {
    // If tree is empty, create a new node as root
    if (root == NULL) {
        root = new Node(val);
        return root;
    }

    // Recursively insert nodes - left if value is smaller, right if larger
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);

    return root;
}

// Function to build BST from array of values
Node* buildBST(vector<int>& nodes) {
    Node* root = NULL;

    // Insert each value into BST
    for (int i = 0; i < nodes.size(); i++) {
        root = insert(root, nodes[i]);
    }

    return root;
}

// Search for a key in BST - Time complexity: O(log n)
Node* search(Node* root, int key) {
    // If tree is empty or key not found at leaf node
    if (root == NULL) {
        cout << "Not Found\n";
        return NULL;
    }

    // Key found at current node    
    if (root->data == key) {
        cout << "Found\n";
        return root;
    }

    // Recursively search left or right subtree based on key value
    if (root->data > key) {
        return search(root->left, key);
    }

    else {
        return search(root->right, key);
    }
}

// Find the smallest value in the right subtree (inorder successor)
Node* inorderSuccessor(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete a node with given value from BST - Time Complexity: O(log n)
Node* deleteNode(Node* root, int val) {
    if (root == NULL) return NULL;

    // Recursively find the node to delete
    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    }
    else {
        // Case 1: Node to delete is a leaf node
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }

        // Case 2: Node has only one child
        else if (!root->left || !root->right) {
            return root->left != NULL ? root->left : root->right;
        }

        // Case 3: Node has two children
        // Replace with smallest value from right subtree (inorder successor)
        Node* IS = inorderSuccessor(root->right);
        root->data = IS->data;
        root->right = deleteNode(root->right, IS->data);
        return root;
    }
}
// Function to print BST in inorder traversal (sorted order)
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);     // Visit left subtree
    cout << root->data << " ";  // Print current node
    inorder(root->right);    // Visit right subtree
}

int main() {
    // Sample array to create BST
    vector<int> nodes = { 5, 1, 3, 4, 2, 7 };

    // Build BST from the array
    Node* root = buildBST(nodes);

    // Print BST elements in ascending order
    cout << "BST before deletion: ";
    inorder(root);
    cout << endl;

    // Delete node with value 3 and print updated BST
    deleteNode(root, 3);
    cout << "BST after deleting 3: ";
    inorder(root);
    return 0;
}