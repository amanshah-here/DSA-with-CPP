#include<iostream>
#include<deque>
using namespace std;

class Queue {
    // deque gives O(1) push_back and pop_front which are perfect for a queue.
    deque<int> dq;
public:
    //* push: add element to the back of the queue
    void push(int val) {
        dq.push_back(val);
    }

    //* pop: remove element from the front of the queue
    void pop() {
        dq.pop_front();
    }

    //* front: return the element at the front
    int front() {
        return dq.front();
    }

    //* Check if the queue is empty
    bool empty() {
        return dq.empty();
    }
};

int main() {
    Queue q;

    // sample usage: enqueue three integers
    q.push(1);
    q.push(2);
    q.push(3);

    // dequeue and print until queue is empty
    while (!q.empty()) {
        cout << q.front() << " "; // prints current front
        q.pop();                    // then remove it
    }

    cout << endl;
    return 0;
}