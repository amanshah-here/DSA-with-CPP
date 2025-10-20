#include<iostream>
#include<queue>
using namespace std;

// Simple stack implementation using two queues.
// push: make the new element be at the front of q1 by
// moving existing elements to q2, pushing new value, then
// moving back. pop/top/empty operate on q1's front.
class Stack {
    queue<int> q1; // main queue holding stack order
    queue<int> q2; // temporary queue used during push
public:
    //* Push element onto stack (O(n) time)
    void push(int val) {
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Insert the new value as front of q1
        q1.push(val);

        // Move back the previous elements
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    //* Remove top element
    void pop() {
        if (empty()) {
            cout << "Stack is Empty.\n";
            return;
        }
        q1.pop();
    }

    //* Return top element
    int top() {
        if (empty()) {
            cout << "Stack is Empty.\n";
            return -1;
        }
        return q1.front();
    }

    //* Check if stack is empty
    bool empty() {
        return q1.size() == 0;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}