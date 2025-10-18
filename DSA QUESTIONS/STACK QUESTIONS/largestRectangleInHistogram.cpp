#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/*
  largestRectangle
  - Purpose: Compute the largest rectangular area in a histogram.
  - Input: vector<int>& heights : heights of histogram bars (non-negative integers)
  - Output: int : maximum rectangular area that can be formed using contiguous bars

  Approach summary:
  - Use a monotonic (increasing) stack of indices to compute, for each bar i,
    the index of the Next Smaller element to the Left (NSL) and the Next Smaller
    element to the Right (NSR). Once NSL and NSR are known, the maximum width
    that the bar i can extend is (NSR[i] - NSL[i] - 1).

  - Area for bar i = heights[i] * width.

  Complexity:
  - Time: O(n) because each index is pushed/popped at most once.
  - Space: O(n) for the stack and the NSL/NSR arrays.
*/

int largestRectangle(vector<int>& heights) {
    stack<int> s; // stack will store indices of bars in increasing order of height
    
    vector<int> nsl(heights.size()); // nsl[i] will hold index of next smaller element to the left of i
    vector<int> nsr(heights.size()); // nsr[i] will hold index of next smaller element to the right of i

    // ---- Compute NSL (Next Smaller on Left) ----
    for (int i = 0; i < heights.size(); i++) {
        while (!s.empty() && heights[i] <= heights[s.top()]) {
            s.pop();
        }
        if (s.empty()) {
            // No smaller element to the left
            nsl[i] = -1;
        } else {
            // top of stack is index of previous smaller element
            nsl[i] = s.top();
        }
        // push current index to be a candidate for future elements
        s.push(i);
    }

    // Emptying the stack if it have any indices from the previous loop.
    while (!s.empty()) {
        s.pop();
    }

    // ---- Compute NSR (Next Smaller on Right) ----
    for (int j = heights.size() - 1; j >= 0; j--) {
        while (!s.empty() && heights[j] <= heights[s.top()]) {
            s.pop();
        }
        if (s.empty()) {
            // No smaller element to the right
            nsr[j] = heights.size();
        } else {
            // top of stack is index of next smaller element to the right
            nsr[j] = s.top();
        }
        s.push(j);
    }

    // ---- Compute maximum area using NSL and NSR ----
    // Initialize maxArea with a very small value. We keep the original
    // initialization to avoid changing runtime behavior in this patch.
    int maxArea = INT8_MIN;
    for (int i = 0; i < heights.size(); i++) {
        // width is number of bars that can be included with height heights[i]
        int width = nsr[i] - nsl[i] - 1;
        int area = width * heights[i];
        
        maxArea = max(area, maxArea); // update global maximum
    }
    return maxArea;
}


int main() {
    // example histogram used for a quick smoke test
    vector<int> heights = { 2, 1, 5, 6, 2, 3 };

    cout << "Largest rectangular area in Histogram: " << largestRectangle(heights) << endl;
    return 0;
}