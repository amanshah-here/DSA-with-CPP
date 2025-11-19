#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// Simple Trie (prefix tree) example
// Node: represents one character and links to children
class Node {
public:
    unordered_map<char, Node*> children; // child character -> node
    bool isEnd;                          // true if node marks end of a word

    Node() : isEnd(false) {}
};

// Trie provides insert, search and startsWith operations
class Trie {
    Node* root;
public:
    Trie() { root = new Node(); }

    // Insert a word into the trie
    void insert(const string& key) {
        Node* temp = root;
        for (char ch : key) {
            if (!temp->children.count(ch))
                temp->children[ch] = new Node();
            temp = temp->children[ch];
        }
        temp->isEnd = true;
    }

    // Return true if the whole word exists
    bool search(const string& key) {
        Node* temp = root;
        for (char ch : key) {
            if (!temp->children.count(ch))
                return false;
            temp = temp->children[ch];
        }
        return temp->isEnd;
    }

    // Return true if any word in trie starts with prefix
    bool startsWith(const string& prefix) {
        Node* temp = root;
        for (char ch : prefix) {
            if (!temp->children.count(ch)) 
                return false;
            temp = temp->children[ch];
        }
        return true;
    }
};

int main() {
    vector<string> words = { "apple", "app", "mango", "man", "woman" };

    Trie trie;
    for (const string& word : words) {
        trie.insert(word); // build trie
    }

    // prints 0 for false, 1 for true
    cout << trie.startsWith("appe") << endl;

    return 0;
}