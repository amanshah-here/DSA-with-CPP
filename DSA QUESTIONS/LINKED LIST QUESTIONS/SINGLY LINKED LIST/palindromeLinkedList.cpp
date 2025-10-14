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
            cout << "List is Empty. " << endl;
        }
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
Node* reverse(Node* head) {  //? function to find reverse of Linked List.
    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node* head) { //TODO: TC: O(n) || SC: O(1)
    if (head->next == NULL) return true; //* corner case: if there is only one node in the Linked List.

    Node* slow = head;  // slow pointer
    Node* fast = head;  // fast pointer

    while (fast != NULL && fast->next != NULL) {  // loop will run until the fast ptr reaches to the tail of the linked List.
        slow = slow->next;          //slow ptr moves 1 step.
        fast = fast->next->next;    //fast ptr moves two step.
    }
    
    // now the slow ptr is at the mid of the Linked List.

    Node* rev = reverse(slow); //new Linked List that will store the 2nd half of the Original Linked List in reversed order.

    while (rev != NULL) { //looping from mid of the LL to the end.
        if (head->data != rev->data) {  // if the 1st element of LL is different from last element then its not palindrome.
            return false;
        }
        head = head->next;
        rev = rev->next;
    }
    return true;    //if it reaches untill here means the LL is palindrome.
}

int main() {
    List l1;

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(3);
    l1.push_back(2);
    l1.push_back(1);
    l1.printList();

    cout << isPalindrome(l1.head) << endl;

    return 0;
}