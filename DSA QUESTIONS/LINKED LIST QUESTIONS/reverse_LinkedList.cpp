#include<iostream>
using namespace std;
class Node {
public:
    Node* next;
    int data;

    Node(int val) {
        next = NULL;
        data = val;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
            next = NULL;
        }
    }
};

class List {
private:
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

    void reverse_LL() {
        Node* prev = NULL;
        Node* curr = head;
        tail = head;

        while (curr != NULL) {
            Node* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head = prev;
    }
};

int main() { 
    List l1;

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    l1.printList();

    l1.reverse_LL();
    l1.printList();
    return 0;
}