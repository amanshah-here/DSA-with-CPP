#include <iostream>
using namespace std;

class CircularQueue {
    int* arr;      // underlying array storage
    int f;         // index of front element
    int r;         // index of rear element

    int capacity;  // maximum number of elements
    int currSize;  // current number of elements
public:

    //* Create a circular queue with given capacity
    CircularQueue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity]; // allocate storage
        currSize = 0;            // empty initially
        f = 0;                   // front starts at 0
        r = -1;                  // rear -1 indicates no elements yet
    }

    //* Insert value at the rear of the queue.
    void enqueue(int val) {
        if (currSize == capacity) {
            cout << "Queue is Full.\n";
            return;
        }

        //* advance rear index with wrap-around using modulo arithmetic
        r = (r + 1) % capacity;
        arr[r] = val;   // place new value at rear
        currSize++;     // increase size counter
    }

    //* Remove the front element from the queue.
    void dequeue() {
        if (empty()) {
            cout << "Queue is Empty.\n";
            return;
        }
        // advance front index with wrap-around; we don't need to clear the value
        f = (f + 1) % capacity;
        currSize--;     // decrease size counter
    }

    //* Return the element at the front without removing it.
    int front() {
        if (empty()) {
            cout << "Queue is Empty.\n";
            return -1;
        }
        return arr[f];
    }

    //* Return true if queue has no elements
    bool empty() {
        return currSize == 0;
    }
};

int main() {
    // Demo: create a queue with capacity 4
    CircularQueue q(4);

    // Enqueue 4 elements (fills the queue). The 5th enqueue shows "Queue is Full."
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5); // should print "Queue is Full." because capacity is 4

    cout << q.front() << endl; // expected 1
    q.dequeue();
    cout << q.front() << endl; // expected 2
    q.enqueue(5);              // space available after one dequeue
    cout << q.front() << endl; // still expected 2 (front unchanged)

    q.dequeue();
    q.enqueue(6);

    // Print remaining elements in FIFO order
    while (!q.empty()) {
        cout << q.front() << " ";
        q.dequeue();
    }
    cout << endl;
    return 0;
}