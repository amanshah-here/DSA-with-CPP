#include<iostream>
using namespace std;

// Simple singly-linked list node used by the Stack.
// T: type of data stored in the node (templated).
template<class T>
class Node {
public:
    T data;         // stored value
    Node* next;     // pointer to the next node in the list

    // Construct a node holding `val`. Next is initialised to nullptr/NULL.
    Node(T val) {
        data = val;
        next = NULL;
    }
};

// Stack implemented using a singly-linked list.
// The head pointer refers to the top of the stack. All operations
// (push/pop/top/isEmpty) operate at the front of the list (O(1)).
template<class T>
class Stack {
    Node<T>* head = NULL;
public:
    // Push a value onto the stack (insert at front).
    void push(T val) {
        // Create a new node with the value.
        Node<T>* newNode = new Node<T>(val);

        // If stack is empty, head becomes the new node.
        if (isEmpty()) {
            head = newNode;
        }
        else {
            // Otherwise link the new node before the current head
            // and update head to be the new node.
            newNode->next = head;
            head = newNode;
        }
    }

    // Pop the top element from the stack. If stack is empty, print a message.
    // This removes the node from the list and frees its memory.
    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty.\n";
            return;
        }

        Node<T>* temp = head;     // node to delete
        head = head->next;        // move head to next element

        temp->next = NULL;        // detach node (not strictly necessary)
        delete temp;              // free memory
    }

    // Return the value at the top of the stack.
    T top() {
        return head->data;
    }

    // Check whether the stack is empty.
    bool isEmpty() {
        return head == NULL;
    }

    // Print and consume the stack. This helper prints all elements from
    // top to bottom and empties the stack by repeatedly calling pop().
    void printStack() {
        if (isEmpty()) {
            cout << "Stack is Empty.\n";
            return;
        }
        
        // Print elements until stack becomes empty.
        while (!isEmpty()) {
            cout << top() << " ";
            pop(); // remove the printed element
        }
        cout << endl;
    }
};

// Example usage of the Stack class.
int main() {
    Stack<char> s;

    // Push characters onto the stack. The sequence pushed will be
    // printed in reverse order because stack is LIFO.
    s.push('n');
    s.push('a');
    s.push('m');
    s.push('a');

    // Prints the stack contents (from top to bottom) and empties it.
    s.printStack();

    return 0;
}