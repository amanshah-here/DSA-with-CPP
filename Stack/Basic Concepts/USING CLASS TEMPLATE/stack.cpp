#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Simple generic stack implementation using a vector as the
// underlying container. The class is a template so it can store any
// copyable type T (int, char, string, user-defined types, etc.).
template <class T>
class Stack {
    vector<T> vec;

public:
    // Push a value onto the top of the stack.
    void push(T val) {
        vec.push_back(val);
    }

    // Pop the top element from the stack. If the stack is empty, print
    // a message and return (no exception thrown).
    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty.\n";
            return;
        }
        vec.pop_back();
    }

    // returns the value at the top of the stack.
    T top() {
        int lastIdx = static_cast<int>(vec.size()) - 1;
        return vec.at(lastIdx); // at() will throw out_of_range if empty
    }

    // True when the stack has no elements.
    bool isEmpty() {
        return vec.size() == 0;
    }

    // Print and empty the stack: repeatedly prints top element and pops
    // it until the stack becomes empty.
    void printStack() {
        while (!isEmpty()) {
            cout << top() << " ";
            pop();
        }
        cout << endl;
    }
};

int main() {
    // Example: stack of integers
    Stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);

    // prints "1 2 3" and empties the stack
    s.printStack();

    // Example: stack of string
    Stack<string> s2;
    s2.push("Tumlog?");
    s2.push("Kaise Ho");
    s2.push("Guys");
    s2.push("Hello!!");

    // prints the strings in LIFO order and empties s2
    s2.printStack();

    // Example: stack of char
    Stack<char> s3;
    s3.push('z');
    s3.push('y');
    s3.push('x');

    // prints "x y z"
    s3.printStack();

    return 0;
}