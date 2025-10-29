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

void topView(Node* root) {
    // BFS queue stores node with its horizontal distance (HD)
    queue<pair<Node*, int>> q; // node, horizontal distance
    // map keeps the first encountered node's data for each HD
    map<int, int> m; // horizontal distance -> node data

    q.push(make_pair(root, 0));

    while (!q.empty()) {
        pair<Node*, int> curr = q.front();
        q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        // record the first node seen at this horizontal distance
        if (m.count(currHD) == 0) {
            m[currHD] = currNode->data;
        }

        // push children with updated HD
        if (currNode->left) {
            q.push(make_pair(currNode->left, currHD - 1));
        }
        if (currNode->right) {
            q.push(make_pair(currNode->right, currHD + 1));
        }
    }

    // map is ordered by HD, so printing values gives left-to-right top view
    for (auto itr : m) {
        cout << itr.second << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nodes = { 1,2,-1,4,-1,5,-1,6,-1,-1,3,-1,-1 };
    
    Node* root = buildTree(nodes);
    topView(root);
    return 0;
}