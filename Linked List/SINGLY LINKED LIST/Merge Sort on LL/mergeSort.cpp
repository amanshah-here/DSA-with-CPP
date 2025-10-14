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

    // ~Node() {
    //     if (next != NULL) {
            // delete next;
    //         next = NULL;
    //     }
    // }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }
    // ~List() {
    //     if (head != NULL) {
    //         delete head;
    //         head = NULL;
    //     }
    // }

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
};

//* Function to split The Linked List into two halves and return the head of right Half.
Node* splitAtMid(Node* head) {
    Node* slow = head;  //slow ptr: Moves one step.  
    Node* fast = head;  //fast ptr: Moves two step.
    Node* prev = NULL;  //prev ptr: to keep track of previous node of slow ptr.
    while (fast != NULL && fast->next != NULL) {    //Looping till end of LL.
        prev = slow;    // storing slow in prev before Updating.
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev != NULL) {
        prev->next = NULL;  //splitting the LL from Middle.
    }

    return slow;    // returning slow: Which is at the head of the 2nd half(rightHead).
}

//* function to merge the splitted lists.
Node* merge(Node* left, Node* right) {
    List ans;    //a temporary LL to store the answers.
    Node* i = left; //head of left ll.
    Node* j = right;    //head of right ll.

    while (i != NULL && j != NULL) {

        //pushing the smaller element b/w right and left list in ans.
        if (i->data <= j->data) {
            ans.push_back(i->data);
            i = i->next;
        }
        else {
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while (i != NULL) { //pushing if left List have any remaining element.
        ans.push_back(i->data);
        i = i->next;
    }

    while (j != NULL) { //pushing if right List have any remaining element.
        ans.push_back(j->data);
        j = j->next;
    }
    return ans.head;
}

Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head; //! Base Case
    }

    Node* rightHead = splitAtMid(head);

    Node* left = mergeSort(head);    //Left Head
    Node* right = mergeSort(rightHead);   //Right Head

    return merge(left, right); //
}

int main() {
    List ll;
    ll.push_back(5);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(1);
    ll.push_back(6);

    ll.printList();

    ll.head = mergeSort(ll.head);
    ll.printList();
}