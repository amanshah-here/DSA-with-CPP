#include<iostream>
#include<string>
using namespace std;

// Node for separate chaining: stores a key, its value, and next pointer
class Node {
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node() {
        // recursively delete next nodes to free the chain
        if (next) {
            delete next;
        }
    }
};

// Basic hash table using separate chaining (array of linked lists)
class HashTable {
    // simple hash: sum of squared char values modulo table size
    int hashFunction(string key) {
        int idx = 0;

        for (char c : key) {
            idx = (idx + (c * c)) % totalSize;
        }

        return idx % totalSize;
    }

    void rehash() { // O(n)
        // double table size and re-insert all existing elements
        Node** oldTable = table;
        int oldSize = totalSize;

        totalSize *= 2;
        currSize = 0;
        table = new Node * [totalSize];

        for (int i = 0; i < totalSize; i++) {
            table[i] = NULL;
        }

        // Copying old data
        for (int i = 0; i < oldSize; i++) {
            Node* temp = oldTable[i];

            while (temp) {
                insert(temp->key, temp->val);
                temp = temp->next;
            }
            if (oldTable[i]) {
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

public:
    int totalSize;
    int currSize;

    Node** table;

    // initialize table with given size
    HashTable(int size = 5) {
        totalSize = size;
        currSize = 0;

        table = new Node * [totalSize];

        for (int i = 0; i < totalSize; i++) {
            table[i] = NULL;
        }
    }

    // insert a key-value pair (front insert for the chain)
    void insert(string key, int val) { // O(1) Avg case
        int idx = hashFunction(key);

        Node* newNode = new Node(key, val);

        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double lambda = currSize / static_cast<double>(totalSize);

        if (lambda > 1) {
            rehash();
        }
    }

    // check whether a key exists in the table
    bool exists(string key) {
        int idx = hashFunction(key);

        Node* temp = table[idx];
        while (temp) {
            if (temp->key == key) return true;
            temp = temp->next;
        }

        return false;
    }

    // return the value for key or -1 if not found
    int search(string key) { // O(1) avg case
        int idx = hashFunction(key);

        Node* temp = table[idx];

        while (temp) {
            if (temp->key == key) {
                return temp->val;
            }
            temp = temp->next;
        }

        return -1;
    }

    // remove a key from the table if present
    void erase(string key) { // O(1) avg case
        int idx = hashFunction(key);

        Node* temp = table[idx];

        Node* prev = temp;
        while (temp) {
            if (temp->key == key) {
                if (temp == prev) {
                    table[idx] = temp->next;
                }
                else {
                    prev->next = temp->next;
                    temp->next = NULL;
                }
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    // print the contents of the table
    void print() {
        for (int i = 0; i < totalSize; i++) {

            cout << "At Index " << i << ": ";
            Node* temp = table[i];

            while (temp) {
                cout << "(" << temp->key << ": " << temp->val << "), ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

// simple example usage of the HashTable
int main() {
    // create a hash table and insert some country populations
    HashTable ht;

    ht.insert("India", 150);
    ht.insert("UK", 120);
    ht.insert("Korea", 56);
    ht.insert("Australia", 65);

    if (ht.exists("Australia")) {
        cout << "Australia's Population: " << ht.search("Australia") << endl;
    }

    ht.erase("UK");

    ht.print();
    return 0;
}