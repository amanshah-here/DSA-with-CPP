#include<iostream>
#include<vector>
using namespace std;

// Simple Stack implementation using vector as the underlying container.
// The stack stores integers and provides the basic operations:
// - push(val): push an element onto the stack
// - pop(): remove the top element (prints a message if stack is empty)
// - top(): return the top element (prints a message and returns 0 if empty)
// - isEmpty(): check whether the stack contains any elements
class Stack {
    vector<int> vec;
public:
    // Push a value onto the stack. This appends to the end of the vector.
    void push(int val) {
        vec.push_back(val);
    }

    // Pop the top value off the stack.
    // If the stack is empty, print a message and do nothing.
    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty.\n";
            return;
        }
        vec.pop_back();
    }

    // Returns the value at the top of the stack.
    int top() {
        if (isEmpty()) {
            cout << "Stack is Empty.\n";
            return -1;
        }
        int topIdx = vec.size() - 1;
        return vec.at(topIdx);
    }

    // Check whether the stack is empty.
    bool isEmpty() {
        return vec.size() == 0;
    }
};

int main() {
    // Demonstration of the Stack class
    Stack s;
    s.push(1); // push 1
    s.push(2); // push 2
    s.push(3); // push 3
    s.push(4); // push 4
    s.push(5); // push 5 (top)

    while (!s.isEmpty()) {  // print the top of stack until stack becomes empty.
        cout << s.top() << " ";
        s.pop();    // pop the top from the stack.
    }
    return 0;
}