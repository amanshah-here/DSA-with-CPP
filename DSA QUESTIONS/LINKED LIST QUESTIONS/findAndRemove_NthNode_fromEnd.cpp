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

    int size_LL() {
        int size = 0;
        Node* temp = head;

        while (temp != NULL) {
            temp = temp->next;
            size++;
        }
        return size;
    }

    void helper(Node* h, int n) {

        int size = size_LL();
        if (n > size) {
            cout << "Invalid Position.\n";
            return;
        }

        int prevPos = size - n;
        Node* prev = h;

        for (int i = 1; i < prevPos; i++) {
            prev = prev->next;// h will finally stop at previous position.
        }
        Node* toDel = prev->next;   //current node to be deleted.
        cout << "Going to delete " << toDel->data << endl;
        prev->next = prev->next->next;  // setting previous->next to the current->next;
    }
    void removeNthnode(int n) {
        helper(head, n);
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

    l1.removeNthnode(2);
    l1.printList();
    return 0;
}