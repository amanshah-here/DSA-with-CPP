#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

// tree node
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

// index for buildTree
static int idx = -1;

Node* buildTree(vector<int>& nodes) {
    idx++;
    // return NULL on marker or end
    if (idx > static_cast<int>(nodes.size()) || nodes[idx] == -1) return NULL;

    // create node and build subtrees
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
}

// find path from root to n (stores node values in path)
bool pathFinder(Node* root, int n, vector<int>& path) {
    if (root == NULL) return false;

    path.push_back(root->data);
    if (root->data == n) return true;

    // search left and right
    int isLeft = pathFinder(root->left, n, path);
    int isRight = pathFinder(root->right, n, path);
    
    if (isLeft || isRight) return true;

    // if not found, backtrack   
    path.pop_back();
    return false;
}

// compute LCA by comparing paths from root
int LCA(Node* root, int n1, int n2) {
    vector<int> path1;
    vector<int> path2;

    pathFinder(root, n1, path1);
    pathFinder(root, n2, path2);

    int LCA = -1;
    for (int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++) {
        if (path1[i] != path2[j]) return LCA;
        LCA = path1[i];
    }
    return LCA;
}

int main() {
    // preorder array; -1 = NULL
    vector<int> nodes = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };

    Node* root = buildTree(nodes);
    cout << "LCA: " << LCA(root, 4, 5);
    return 0;
}