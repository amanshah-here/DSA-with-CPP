#include<iostream>
#include<vector>
#include<Stack>
using namespace std;

// Compute the Next Greater Element to the right for each element in 'arr'.
// Inputs:
//  - arr : input vector of integers
//  - ans : reference vector (pre-sized) where ans[i] will hold the next greater
//          element to the right of arr[i], or -1 if none exists
// Algorithm:
//  - Iterate from right-to-left and maintain a stack of candidate "next greater"
//    elements. Pop elements from the stack that are <= current element because
//    they cannot be the next greater for any element to the left. The top of
//    the stack (if any) is the next greater element for the current index.
//  - Time complexity: O(n) on average because each element is pushed/popped at most once.

void nextGreater(vector<int> arr, vector<int>& ans) {
    stack<int> s; // stack holds potential next-greater values

    // The right-most element has no elements to its right, so its answer is -1.
    ans[ans.size() - 1] = -1;
    s.push(arr[arr.size() - 1]); 

    // Process elements from second-last to first
    for (int i = arr.size() - 2; i >= 0; i--) {
        // Remove elements from stack that are not greater than current element
        while (!s.empty() && arr[i] >= s.top()) {
            s.pop();
        }

        // If stack is empty, there's no greater element to the right
        if (s.empty()) {
            ans[i] = -1;
        }
        else {
            int nextHigh = s.top();
            ans[i] = nextHigh; // nearest greater element to the right
        }

        // Push current element as a candidate for elements to the left
        s.push(arr[i]);
    }

    // Print the resulting next-greater values (space-separated)
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Example usage
    vector<int> arr = { 6, 8, 0, 1, 3 };
    vector<int> ans(arr.size());
    nextGreater(arr, ans);

    return 0;
}