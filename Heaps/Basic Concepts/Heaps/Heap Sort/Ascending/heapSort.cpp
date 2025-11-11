#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Maintain max heap property by moving larger element up
void heapify(int idx, vector<int>& arr, int n) {
    if (idx >= n) return; // Base case: index out of bounds

    int left = (idx * 2) + 1;  // Left child index
    int right = (idx * 2) + 2; // Right child index
    int maxIdx = idx;          // Track index of maximum element

    if (left < n && arr[left] > arr[maxIdx]) {
        maxIdx = left; // Left child is larger
    }
    if (right < n && arr[right] > arr[maxIdx]) {
        maxIdx = right; // Right child is larger
    }

    if (idx != maxIdx) {
        swap(arr[maxIdx], arr[idx]); // Swap to maintain heap property

        heapify(maxIdx, arr, n); // Recursively heapify affected subtree
    }
}

// Sort array using heap sort algorithm
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build max heap by heapifying from bottom-up
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(i, arr, n);
    }

    // Extract elements one by one and place at end
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // Move max element to end
        heapify(0, arr, i);   // Restore heap property for remaining elements
    }
}

// Driver function to test heap sort
int main() {
    vector<int> arr = { 1, 4, 2, 5, 3 }; // Initialize test array

    heapSort(arr); // Perform heap sort

    for (int i : arr) { // Print sorted array
        cout << i << " ";
    }

}