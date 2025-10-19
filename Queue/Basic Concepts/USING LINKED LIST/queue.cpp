#include<iostream>
using namespace std;

//* Node<T> - singly linked list node that holds a value of type T.
template<class T>
class Node {
public:
    T data;        // stored value
    Node* next;    // pointer to the next node in the list (or nullptr)

    // Construct a node with given value. 'next' is initialized to nullptr.
    Node(T val) {
        this->data = val;
        this->next = nullptr;
    }
};

//* Queue<T> - a queue backed by a singly linked list. We keep head and tail
//* pointers to support O(1) enqueue and dequeue operations.
template <class T>
class Queue {
    Node<T>* head; // front of the queue (where we dequeue)
    Node<T>* tail; // back of the queue (where we enqueue)
public:
    // Create an empty queue.
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    //* enqueue: add an element to the back of the queue. O(1) time.
    void enqueue(T val) {   
        Node<T>* newNode = new Node<T>(val);
        if (empty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    //* dequeue: remove the front element from the queue. O(1) time.
    //* If the queue is empty we print a message and return without throwing.
    void dequeue() {   
        if (empty()) {
            cout << "Queue is Empty.\n";
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    //* front: return the value at the front of the queue in O(1) time.
    T front() { 
        return head->data;
    }

    //* empty: check whether the queue has no elements. O(1) time.
    bool empty() {  
        return head == nullptr;
    }
};

int main() {
    Queue<int> q1;

    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);

    while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.dequeue();
    }
    cout << endl;

    return 0;
}