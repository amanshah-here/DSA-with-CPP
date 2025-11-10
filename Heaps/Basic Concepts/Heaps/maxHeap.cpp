#include<iostream>
#include<vector>
using namespace std;

// Simple max-heap implementation using a vector.
// Provides: push (insert), top (peek max), pop (remove max), and empty check.
class Heap {
    vector<int> vec;
public:

    // Insert value into the heap.
    // Uses sift-up (bubble up) to restore max-heap property. O(log n) average.
    void push(int val) {
        vec.push_back(val);

        int chIdx = vec.size() - 1;
        int parIdx = (chIdx - 1) / 2;

        while (parIdx >= 0 && vec[chIdx] > vec[parIdx]) {   // O(logn)
            swap(vec[chIdx], vec[parIdx]);
            chIdx = parIdx;
            parIdx = (chIdx - 1) / 2;
        }
    }

    // Restore max-heap property starting from index `idx` (sift-down).
    void heapify(int idx) {

        // 1) Guard: if starting index is outside the heap, nothing to do.
        if (idx >= vec.size()) return;

        // 2) Compute child indices for the current node
        int left = (2 * idx) + 1;   // left child index
        int right = (2 * idx) + 2;  // right child index

        // 3) Assume the current node is the largest
        int maxIdx = idx;

        // If left child exists and is greater than current max, update maxIdx
        if (left < vec.size() && vec[left] > vec[maxIdx]) {
            maxIdx = left;
        }

        // If right child exists and is greater than current max, update maxIdx
        if (right < vec.size() && vec[right] > vec[maxIdx]) {
            maxIdx = right;
        }

        // 4) If the largest element is not the parent, swap it with the parent
        if (maxIdx != idx) {
            swap(vec[idx], vec[maxIdx]);
            // Recursive call continues the sift-down from the child that received
            // the smaller value.
            heapify(maxIdx);
        }
    }

    // Remove the root (maximum).
    void pop() {
        // Move last element to root and sift-down.
        swap(vec[0], vec[vec.size() - 1]);

        vec.pop_back();

        heapify(0);
    }

    // Return current maximum element (root). Caller should ensure heap not empty.
    int top() {
        return vec.front();
    }

    // Check if heap has no elements.
    bool empty() {
        return vec.empty();
    }
};

int main() {
    Heap h;
    // Demo: insert some values and then pop all while printing the current max
    h.push(1);
    h.push(11);
    h.push(23);
    h.push(3);
    h.push(102);

    while (!h.empty()) {
        cout << "Top: " << h.top() << endl;
        h.pop();
    }

    return 0;
}