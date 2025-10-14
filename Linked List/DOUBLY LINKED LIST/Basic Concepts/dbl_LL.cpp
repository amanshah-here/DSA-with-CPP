#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            // attach newNode before current head
            head->prev = newNode;
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
            // attach newNode after current tail
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insert(int pos, int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            cout << "List was Empty, node inserted as 1st node.\n";
        }
        else {
            Node* temp = head;
            int i = 0;
            while (i++ < pos - 1) {
                if (temp == NULL) {
                    cout << "Position is Invalid.\n";
                    return;
                }
                temp = temp->next;
            }
            //temp is now at position - 1 node i.e previous node.
            newNode->next = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            // update the backward link of the node following newNode if it exists
            if (newNode->next != NULL) {
                newNode->next->prev = newNode;
            } else {
                // inserted at the end -> update tail
                tail = newNode;
            }
        }
    }

    void pop_front() {
        if (head == NULL) {
            cout << "List is Empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }

        temp->next = NULL;
        delete temp;
    }

    void pop_back() {
        if (head == NULL) {
            cout << "List is Empty.\n";
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        }

        temp->prev = NULL;
        delete temp;
    }

    void printList() {
        if (head == NULL) {
            cout << "List is Empty.\n";
            return;
        }
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyList ll;
    ll.push_front(2);
    ll.push_front(1);

    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.printList();

    ll.insert(3, 5);
    ll.printList();

    ll.pop_front();
    ll.pop_back();
    ll.printList();
    return 0;
}