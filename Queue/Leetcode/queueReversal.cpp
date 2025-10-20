#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reversal(queue<int>& q) {
    stack<int> s;

    // Move all elements from the queue to the stack.
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Move elements back from the stack into the queue.
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

int main() {
    queue<int> q;

    // Fill queue with numbers 1..10
    for (int i = 1; i <= 10; i++) {
        q.push(i);
    }

    // Reverse the queue in-place
    reversal(q);

    // Print reversed queue (expected output: 10 9 8 7 6 5 4 3 2 1 )
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}