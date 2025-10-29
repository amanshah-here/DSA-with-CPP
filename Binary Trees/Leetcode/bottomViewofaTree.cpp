#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

// Basic binary tree node
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
static int idx = -1;

Node* buildTree(vector<int>& nodes) {
    idx++;
    // If out of range or marker (-1) found, return NULL
    if (idx > static_cast<int>(nodes.size()) || nodes[idx] == -1) return NULL;

    // create current node and recursively build left/right
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
}

// Function to find bottom view of binary tree
void bottomView(Node* root) {
    // Queue stores node and its horizontal distance from root
    queue<pair<Node*, int>> q;
    // Map stores horizontal distance -> node value
    map<int, int> m;

    // Start with root node at horizontal distance 0
    q.push(make_pair(root, 0));

    while (!q.empty()) {
        pair<Node*, int> curr = q.front();
        q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        // Update value for current horizontal distance
        m[currHD] = currNode->data;

        // Add left child with HD-1
        if (currNode->left) {
            q.push(make_pair(currNode->left, currHD - 1));
        }
        // Add right child with HD+1
        if (currNode->right) {
            q.push(make_pair(currNode->right, currHD + 1));
        }
    }

    // Print bottom view nodes from left to right
    for (auto itr : m) {
        cout << itr.second << " ";
    }
    cout << endl;
}

int main() {
    // Tree data in array form, -1 represents NULL nodes
    vector<int> nodes = { 1,2,-1,4,-1,5,-1,6,-1,-1,3,-1,-1 };

    Node* root = buildTree(nodes);
    bottomView(root);
    return 0;
}