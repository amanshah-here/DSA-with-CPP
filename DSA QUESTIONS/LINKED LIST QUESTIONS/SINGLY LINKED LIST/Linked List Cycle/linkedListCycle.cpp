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

bool isCycle(Node* head) {
    if (head == nullptr) return false;   //if list is empty means no cycle exists.

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {    //looping until the end of the List if exists.
        slow = slow->next;  //slow ptr: moves 1 step.
        fast = fast->next->next;    //fast ptr: moves 2 step.

        if (slow == fast) {   // if slow and fast meets at same position means cycle exists.
            cout << "Cycle Exists.\n";
            return true;
        }
    }
    cout << "Cycle doesn't Exists.\n";
    return false;
}

int main() {
    List l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(1);
    l1.tail->next = l1.head;

    cout << isCycle(l1.head) << "\n";
    return 0;
}