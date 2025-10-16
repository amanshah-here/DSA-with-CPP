#include<iostream>
#include<stack>
using namespace std;

// This program demonstrates how to reverse a stack using recursion
// without using any extra stack or array. It uses two functions:
// 1) pushAtBottom - inserts an element at the bottom of a stack
// 2) reverseStack - reverses the stack by recursively moving elements

void pushAtBottom(stack<int>& s, int val) {
    // Base case: if stack is empty, the value becomes the bottom element
    if (s.empty()) {
        s.push(val);
        return;
    }

    // Remove the top element and hold it temporarily
    int temp = s.top();
    s.pop();

    // Recurse until stack is empty, then push the new value
    pushAtBottom(s, val);

    // Restore the removed element back on top
    s.push(temp);
}

//* function to reverse the stack.
void reverseStack(stack<int>& s) {  // TC: O(n) 
    // If stack is empty, nothing to reverse
    if (s.empty()) {
        return;
    }

    // Remove the top element and reverse the remaining stack  
    int temp = s.top();
    s.pop();
    reverseStack(s);

    // Push the previously removed element at the bottom so
    // the order gets reversed as recursion unwinds
    pushAtBottom(s, temp);
}

void printStack(stack<int> s) {
    // Print elements from top to bottom. We take the stack by value
    // so we can pop elements without modifying the original stack.
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;

    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    // Current stack (top to bottom): 1 2 3 4
    printStack(s);

    // Reverse the stack and print again
    reverseStack(s);
    // After reversing, stack (top to bottom) should be: 4 3 2 1
    printStack(s);
    return 0;
}