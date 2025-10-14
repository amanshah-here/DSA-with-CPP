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
public:
    Node* head;
    Node* tail;

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


    void printList() {
        if (head == NULL) {
            cout << "List is Empty.\n";
        }
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// I implemented a small List wrapper with push_back and printList so I can build and
// display lists easily while testing cycle detection and removal.

Node* isCycle(Node* head) {
    if (head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) break;
    }

    // if there was no meeting point, there is no cycle
    if (slow != fast) return NULL;

    while (slow != head) {  //finding the start of the cycle.
        head = head->next;
        slow = slow->next;
    }
    return head;    //returning the start of the cycle. 
}

void removeCycle(Node* head) {
    Node* cyclicNode = isCycle(head);
    if (cyclicNode == NULL) {
        cout << "No Cycle Exists.\n";
        return;
    }

    // Finding the node just before the start of the cycle
    Node* ptr = cyclicNode;
    while (ptr->next != cyclicNode) {
        ptr = ptr->next;
    }

    // breaking the cycle
    ptr->next = NULL;
    cout << "Cycle removed.\n";
}

int main() {
    List l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(1);
    l1.tail->next = l1.head;

    removeCycle(l1.head);
    l1.printList();
    return 0;
}