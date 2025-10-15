#include<iostream>
#include<list>
using namespace std;

// Simple stack implementation using the STL `list` as the underlying container.
// The class is a template so it can store any copyable type T.
template<class T>
class Stack {
    list<T> ll;

public:
    // Push a value onto the stack (make it the new top).
    void push(T val) {
        ll.push_front(val);
    }

    // Pop the top value from the stack. If the stack is empty print a message and return.
    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty.\n";
            return;
        }
        ll.pop_front();
    }

    // Return the current top value.
    T top() {
        return ll.front();
    }

    // Check if the stack contains no elements.
    bool isEmpty() {
        return ll.size() == 0;
    }

    // Print and empty the stack by repeatedly printing the top and popping it.
    void printStack() {
        while (!isEmpty()) {
            cout << top() << " ";
            pop();
        }
        cout << endl;
    }
};

// Demo usage of the Stack template.
int main() {
    // Integer stack
    Stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);

    // prints: 1 2 3
    s.printStack();

    // Character stack
    Stack<char> s2;
    s2.push('n');
    s2.push('a');
    s2.push('m');
    s2.push('a');

    // prints: a m a n
    s2.printStack();

    return 0;
}