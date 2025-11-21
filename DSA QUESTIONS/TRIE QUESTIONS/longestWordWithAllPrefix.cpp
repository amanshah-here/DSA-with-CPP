#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// Trie node structure
class Node {
public:
    unordered_map<char, Node*> children; // Map of child nodes
    bool isEnd;                          // Word end marker

    Node() : isEnd(false) {}
};

// Trie class
class Trie {
    Node* root;
public:
    Trie() { root = new Node(); }

    // Insert string into trie
    void insert(const string& key) {
        Node* cur = root;
        for (char ch : key) {
            if (!cur->children.count(ch))
                cur->children[ch] = new Node();
            cur = cur->children[ch];
        }
        cur->isEnd = true;
    }

    // Search for complete word
    bool search(const string& key) {
        Node* cur = root;
        for (char ch : key) {
            if (!cur->children.count(ch))
                return false;
            cur = cur->children[ch];
        }
        return cur->isEnd;
    }

    // Check if prefix exists
    bool startsWith(const string& prefix) {
        Node* cur = root;
        for (char ch : prefix) {
            if (!cur->children.count(ch))
                return false;
            cur = cur->children[ch];
        }
        return true;
    }
    // DFS to find longest word with all prefixes
    string longestStrHelper(Node* root, string& ans, string temp) {
        // Traverse all children
        for (auto& pair : root->children) {
            // If child is word end, update answer if longer or lexicographically smaller
            if (pair.second->isEnd) {
                temp += pair.first;

                if (temp.size() == ans.size() && temp < ans || temp.size() > ans.size()) {
                    ans = temp;
                }
                longestStrHelper(pair.second, ans, temp);
                temp = temp.substr(0, temp.size() - 1);
            }
        }
    }

    // Get longest word where all prefixes exist
    string longestStrWithEOW() {
        string ans = "";
        longestStrHelper(root, ans, "");
        return ans;
    }
};

// Find longest string with all prefixes in dictionary
string longestString(vector<string>& dict) {
    // Build trie and find longest word
    Trie trie;

    for (string s : dict) {
        trie.insert(s);
    }

    return trie.longestStrWithEOW();
}

int main() {
    vector<string> dict = { "a", "banana", "app", "appl", "ap", "apply", "apple" };

    cout << "Longest Word With All Prefixes: " << longestString(dict) << endl;

    return 0;
}