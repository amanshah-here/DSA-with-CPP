#include<iostream>
#include<stack>
using namespace std;

//* Simple queue implemented using two stacks (enqueue is O(n), dequeue is O(1)).
class Queue {
    stack<int> s1; // main stack holding queue elements in correct order
    stack<int> s2; // auxiliary stack used during enqueue
public:
    //* Insert element at the back of the queue
    void enqueue(int val) {
        // move all elements to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        // push new element
        s1.push(val);

        // move elements back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    

    //* Remove element from the front
    void dequeue() {
        if (empty()) {
            cout << "Queue is Empty.\n";
            return;
        }
        s1.pop();
    }

    //* Get the front element
    int front() {
        if (empty()) {
            cout << "Queue is Empty.\n";
            return -1;
        }
        return s1.top();
    }

    //* Check if queue is empty
    bool empty() {
        return s1.size() == 0;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.dequeue();
    }

    return 0;
}