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

Node* detectCycle(Node* head) {
    if (head == nullptr) return nullptr; //if List is empty no cycle exists.
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {    // looping until fast reaches the end if exists.
        slow = slow->next;  //slow ptr: moves one step.
        fast = fast->next->next;    //fast ptr: moves two step.

        if (slow == fast) {   //if fast and slow meets at same position the break, means cycle exists.
            break;
        }
    }

    if (fast == nullptr || fast->next == nullptr) return nullptr;    // if there is no cycle means the loops exits at the end.

    while (slow != head) {    //if cycle exists then looping until slow and head meets at same position. 
        head = head->next;
        slow = slow->next;
    }
    return head;
}

int main() {
    List l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    l1.tail->next = l1.head;

    cout << "Tail connect to node address: " << detectCycle(l1.head) << endl;
}