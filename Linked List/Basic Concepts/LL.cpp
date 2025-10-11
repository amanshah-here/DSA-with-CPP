#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
            next = NULL;
        }
    }
};

class List {
    Node* head;
    Node* tail;
public:
    List() {
        head = NULL;
        tail = NULL;
    }

    ~List() {
        if (head != NULL) {
            delete head;
            head = NULL;
        }
    }

    void push_front(int val) {
        Node* newNode = new Node(val);  //dynamic memory allocation
        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insert(int val, int pos) {
        Node* newNode = new Node(val);
        Node* temp = head;
        int i = 0;
        while (i++ < pos - 1) {
            if (temp == NULL) {
                cout << "POSITION IS INVALID.\n";
                return;
            }
            temp = temp->next;

        }
        //temp is now at position - 1 node i.e previous node.
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void printList() {
        if (head == NULL) {
            cout << "List is Empty. " << endl;
        }
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void pop_front() {
        if (head == NULL) {
            cout << "List is Empty.\n";
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back() {
        if (head == NULL) {
            cout << "List is Empty.\n";
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
            // cout << temp->data << endl;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    int searchItr(int key) {
        if (head == NULL) {
            cout << "List is Empty.\n";
        }
        int idx = 0;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == key) {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }
    int helper_rec(int key, Node* temp) {
        if (temp == NULL) {
            return -1;
        }
        if (temp->data == key) {
            return 0;
        }
        int idx = helper_rec(key, temp->next);

        if (idx == -1) {
            return -1;
        }

        return idx + 1;
    }
    int searchRec(int key) {
        return helper_rec(key, head);
    }
};

int main() {
    List l1;

    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);

    l1.push_back(4);
    l1.push_back(5);
    l1.printList();
    cout << l1.searchItr(5) << endl;
    cout << l1.searchRec(3) << endl;
    // l1.insert(100, 2);
    // l1.pop_back();
    l1.printList();

    return 0;
}