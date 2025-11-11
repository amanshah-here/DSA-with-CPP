#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Maintain max heap property by moving larger element up
void heapify(int idx, vector<int>& arr, int n) {
    if (idx >= n) return; // Base case: index out of bounds

    int left = (idx * 2) + 1;  // Left child index
    int right = (idx * 2) + 2; // Right child index
    int minIdx = idx;          // Track index of minimum element

    if (left < n && arr[left] < arr[minIdx]) {
        minIdx = left; // Left child is smller
    }
    if (right < n && arr[right] < arr[minIdx]) {
        minIdx = right; // Right child is smller
    }

    if (idx != minIdx) {
        swap(arr[minIdx], arr[idx]); // Swap to maintain heap property

        heapify(minIdx, arr, n); // Recursively heapify affected subtree
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