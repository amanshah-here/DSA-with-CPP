#include<iostream>
#include<vector>
using namespace std;

// Min Heap implementation using vector
class Heap {
    vector<int> vec;  // Stores heap elements
public:

    // Insert value and maintain heap property by moving up
    void push(int val) {
        vec.push_back(val);

        // Get child index and parent index
        int chIdx = vec.size() - 1;
        int parIdx = (chIdx - 1) / 2;

        // Move up until min heap property satisfied
        while (parIdx >= 0 && vec[chIdx] < vec[parIdx]) {
            swap(vec[chIdx], vec[parIdx]);
            chIdx = parIdx;
            parIdx = (chIdx - 1) / 2;
        }
    }

    // Move down node to maintain min heap property
    void heapify(int idx) {
        // Base case: index out of bounds
        if (idx >= vec.size()) return;

        // Get left and right child indices
        int left = (2 * idx) + 1;
        int right = (2 * idx) + 2;

        // Assume current node is smallest
        int maxIdx = idx;

        // Check if left child is smaller
        if (left < vec.size() && vec[left] < vec[maxIdx]) {
            maxIdx = left;
        }

        // Check if right child is smaller
        if (right < vec.size() && vec[right] < vec[maxIdx]) {
            maxIdx = right;
        }

        // Swap if a child was smaller, then recursively heapify
        swap(vec[idx], vec[maxIdx]);
        if (maxIdx != idx) {
            heapify(maxIdx);
        }
    }

    // Remove minimum element from heap
    void pop() {
        // Move last element to root
        swap(vec[0], vec[vec.size() - 1]);

        // Remove last element
        vec.pop_back();

        // Restore heap property
        heapify(0);
    }

    // Return minimum element
    int top() {
        return vec.front();
    }

    // Check if heap is empty
    bool empty() {
        return vec.empty();
    }
};

int main() {
    Heap h;

    // Insert elements into min heap
    h.push(1);
    h.push(11);
    h.push(23);
    h.push(3);
    h.push(102);

    // Extract and print all elements in sorted order
    while (!h.empty()) {
        cout << "Top: " << h.top() << endl;
        h.pop();
    }
    return 0;
}