#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// Trie node: stores children and a flag for word end
class Node {
public:
    unordered_map<char, Node*> children; // child char -> child node
    bool isEnd;                          // true if node marks end of a word

    Node() : isEnd(false) {}
};

// Simple Trie with insert/search/prefix helpers
class Trie {
    Node* root;
public:
    Trie() { root = new Node(); }

    // Insert a string into the trie (creates missing nodes)
    void insert(const string& key) {
        Node* cur = root;
        for (char ch : key) {
            if (!cur->children.count(ch))
                cur->children[ch] = new Node();
            cur = cur->children[ch];
        }
        cur->isEnd = true;
    }

    // Check whether a full word exists in the trie
    bool search(const string& key) {
        Node* cur = root;
        for (char ch : key) {
            if (!cur->children.count(ch))
                return false;
            cur = cur->children[ch];
        }
        return cur->isEnd;
    }

    // Check whether any word starts with the given prefix
    bool startsWith(const string& prefix) {
        Node* cur = root;
        for (char ch : prefix) {
            if (!cur->children.count(ch))
                return false;
            cur = cur->children[ch];
        }
        return true;
    }

    // Recursively count nodes in subtree rooted at `root`
    int countHelper(Node* node) {
        int cnt = 0; 
        for (auto& p : node->children)
            cnt += countHelper(p.second);
        return cnt + 1;
    }

    // Return total number of nodes in the trie (including root)
    int countNodes() {
        return countHelper(root);
    }
};

// Build a trie of all suffixes of `str` and return the node count.
// Distinct substrings = (number of trie nodes) - 1 (exclude root).
int countUniqueSubstr(const string& str) {
    Trie trie;
    for (int i = 0; i < str.size(); ++i) {
        trie.insert(str.substr(i)); // insert each suffix
    }
    return trie.countNodes(); // includes root
}

int main() {
    string str = "ababa"; // sample input
    cout << "total unique substring: " << countUniqueSubstr(str) << endl;
    return 0;
}