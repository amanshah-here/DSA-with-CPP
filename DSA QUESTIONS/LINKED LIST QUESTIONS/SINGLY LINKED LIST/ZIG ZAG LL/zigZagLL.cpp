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
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
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

//
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL) {
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
    return head;
}

Node* splitAtMid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    // if prev is NULL, the list has 0 or 1 element; return head as right half
    if (prev != NULL) prev->next = NULL;
    return slow;
}

Node* MergeZigZag(Node* left, Node* right) {
    List ans;

    // weave nodes from left and right alternately
    while (left != NULL && right != NULL) {
        ans.push_back(left->data);
        left = left->next;
        ans.push_back(right->data);
        right = right->next;
    }

    // append remaining nodes from left or right
    while (left != NULL) {
        ans.push_back(left->data);
        left = left->next;
    }
    while (right != NULL) {
        ans.push_back(right->data);
        right = right->next;
    }

    return ans.head;
}

Node* zigZag(Node* head) {
    Node* rightHead = splitAtMid(head);
    Node* rev = reverse(rightHead);
    return MergeZigZag(head, rev);
}

int main() {
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);
    ll.push_back(9);
    ll.printList();

    ll.head = zigZag(ll.head);
    ll.printList();
    return 0;
}