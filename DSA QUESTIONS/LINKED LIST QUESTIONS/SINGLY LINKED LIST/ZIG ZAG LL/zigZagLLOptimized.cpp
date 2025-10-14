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

//* function to merge the splitted lists.
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

//* Function to split The Linked List into two halves and return the head of right Half.
Node* splitAtMid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if (prev != NULL) prev->next = NULL;    // if prev is NULL, the list has 0 or 1 element; return head as right half
    return slow;
}

//* function for alternate merging.
Node* mergeZigZag(Node* left, Node* right) {
    Node* head = left;  // I set head to the start of the new list (left half's head).

    // I use tail to keep track of the last node I connected. Initially it points to right
    // to simplify the final connection logic in case right has remaining nodes.
    Node* tail = right;

    while (left != NULL && right != NULL) {
        Node* nextLeft = left->next;   // I remember where left originally pointed
        Node* nextRight = right->next; // I remember where right originally pointed

        
        left->next = right; // I splice the right node after the left node
        
        right->next = nextLeft; // I continue the chain by pointing right->next to the nextLeft
        
        tail = right;   // I update tail to the most recently appended node (right)

        // I advance left and right to continue weaving
        left = nextLeft;
        right = nextRight;
    }

    // If right still has nodes left (right is longer), I attach the remaining right nodes
    // after tail. If left has nodes left, they are already connected in place.
    if (right != NULL) {
        tail->next = right;
    }
    
    return head;    // I return the head of the newly merged zig-zag list.
}

//* function that calls other helper functions.
Node* zigZag(Node* head) {
    Node* rightHead = splitAtMid(head); //storing the head of 2nd half of LL.
    Node* rightHeadRev = reverse(rightHead);    //reversing the 2nd half of LL.
    return mergeZigZag(head, rightHeadRev); //alternate merging to create zigZag LL.
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