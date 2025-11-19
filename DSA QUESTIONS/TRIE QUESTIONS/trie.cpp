#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

// Trie node: stores children links and end-of-word flag
class Node {
public:
    // map from character to child node
    unordered_map<char, Node*> children;
    // true if node represents end of a word
    bool isEnd;

    Node() {
        // initialize end marker
        isEnd = false;
    }
};

// Trie wrapper: holds pointer to root node
class Trie {
    // root node of the trie
    Node* root;
public:
    Trie() {
        // create empty root
        root = new Node();
    }

    // insert a word into the trie (O(length of key))
    void insert(string key) { 
        Node* temp = root;

        for (int i = 0; i < key.size(); i++) {
            // create child node if missing
            if (!temp->children.count(key[i])) {
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        // mark end of word
        temp->isEnd = true;
    }

    // search for exact word in trie (O(length of key))
    bool search(string key) { 

        Node* temp = root;
        for (int i = 0; i < key.size(); i++) {
            // missing character => not found
            if (!temp->children.count(key[i])) {
                return false;
            }
            temp = temp->children[key[i]];
        }
        // return true only if node marks end of a word
        return temp->isEnd;
    }
};


int main() {
    // sample words to insert
    vector<string> words = { "the", "a", "there", "their", "any", "thee" };

    Trie trie; // create trie instance

    for (string str : words) {
        trie.insert(str); // insert each word
    }

    // print search result for "any" (1 = true, 0 = false)
    cout << trie.search("any");

    return 0;
}