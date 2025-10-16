#include<iostream>
#include<stack>
using namespace std;
/*
→ Demonstrates how to insert an element at the bottom of a stack using recursion.
→ The code keeps the original order of the other elements while placing the new value at the very bottom.
*/


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
    // Stack now (top -> bottom): 1 2 3 4
    printStack(s);

    // Insert 5 at the bottom. After this operation the stack
    // (top -> bottom) will be: 1 2 3 4 5
    pushAtBottom(s, 5);
    printStack(s);

    return 0;
}