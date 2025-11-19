#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// Simple Trie node
class Node {
public:
    unordered_map<char, Node*> children; // child links for characters
    bool isEnd;                          // marks end of a full word
    int freq;                            // number of words passing through this node

    Node() {
        isEnd = false;
        freq = 0;
    }
};

// Trie with insert and prefix extraction
class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
        root->freq = -1; // root uses -1 as a sentinel (not used for prefix logic)
    }

    // Insert a word into the trie and update node frequencies
    void insert(const string& key) {
        Node* temp = root;
        for (char ch : key) {
            if (!temp->children.count(ch)) {
                // create child if missing and initialize freq
                temp->children[ch] = new Node();
                temp->children[ch]->freq = 1;
            }
            else {
                // another word passes through this child
                temp->children[ch]->freq++;
            }
            temp = temp->children[ch];
        }
        temp->isEnd = true; // mark word end
    }

    // Return the shortest unique prefix for key
    string getPrefix(const string& key) {
        Node* temp = root;
        string prefix = "";

        for (int i = 0; i < key.size(); i++) {
            prefix += key[i];
            // when freq==1 this prefix is unique among inserted words
            if (temp->children[key[i]]->freq == 1) {
                return prefix;
            }
            temp = temp->children[key[i]];
        }
        return prefix; // fallback (whole word)
    }
};


// Build trie from words and collect shortest unique prefixes
vector<string> shortestPrefix(vector<string>& words) {
    Trie trie;
    for (string& str : words) {
        trie.insert(str);
    }

    vector<string> ans;
    for (string& str : words) {
        ans.push_back(trie.getPrefix(str));
    }

    return ans;
}

int main() {
    // sample input
    vector<string> words = { "zebra", "dog", "duck", "dove" };

    vector<string> ans = shortestPrefix(words);

    // print prefixes
    for (const string& str : ans) {
        cout << str << " ";
    }

    return 0;
}