#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

// Trie node
class Node {
public:
    unordered_map<char, Node*> children; // child links
    bool isEnd;                          // end of a valid word

    Node() {
        isEnd = false;
    }
};

// Trie structure
class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    // Insert a word into the trie
    void insert(string key) {
        Node* temp = root;
        for (char ch : key) {
            if (!temp->children.count(ch))
                temp->children[ch] = new Node();
            temp = temp->children[ch];
        }
        temp->isEnd = true;
    }

    // Check if a word exists in the trie
    bool search(string key) {
        Node* temp = root;
        for (char ch : key) {
            if (!temp->children.count(ch))
                return false;
            temp = temp->children[ch];
        }
        return temp->isEnd;
    }
};

// Try splitting the string recursively
bool wordBreakHelper(string key, Trie& trie, vector<string>& ans) {

    if (key.size() == 0) return true;   // whole string used

    for (int i = 0; i < key.size(); i++) {
        string first = key.substr(0, i + 1);   // prefix
        string second = key.substr(i + 1);      // remaining

        // If prefix is a dictionary word
        if (trie.search(first)) {
            ans.push_back(first);

            // If remaining part is also valid
            if (wordBreakHelper(second, trie, ans))
                return true;

            ans.pop_back(); // backtrack
        }
    }
    return false; // no valid split found
}

// Build trie and start recursive splitting
vector<string> wordBreak(vector<string>& dictionary, string key) {
    Trie trie;
    for (string str : dictionary)
        trie.insert(str);

    vector<string> ans;
    wordBreakHelper(key, trie, ans);
    return ans;
}

int main() {
    vector<string> dictionary = { "i", "like", "sam", "samsung", "mobile", "ice" };
    string key = "ilikesamsung";

    vector<string> ans = wordBreak(dictionary, key);

    for (string str : ans) {
        cout << str << " ";
    }

    return 0;
}