#include<iostream>
#include<vector>
#include<queue>
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

vector<vector<int>> levelOrder(Node* root) { // O(N) - inorder traversal: left, root, right
    vector<vector<int>> ans;
    if (root == NULL) return ans;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            Node* currNode = q.front();
            q.pop();

            level.push_back(currNode->data);

            if (currNode->left) q.push(currNode->left);
            if (currNode->right) q.push(currNode->right);
        }
        ans.push_back(level);
    }
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

    vector<vector<int>> ans = levelOrder(root);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " , ";
        }
        cout << endl;
    }
    return 0;
}