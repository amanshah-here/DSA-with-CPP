#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Returns sliding window maximums for each window of size k
vector<int> slidingWindow(vector<int>& arr, int k) {

    // max-heap of pairs (value, index)
    priority_queue<pair<int, int>> pq;
    
    // push first k elements (value, index)
    for (int i = 0; i < k; i++) {
        pq.push({ arr[i], i });
    }
    vector<int> ans;
    // record max of the first window 
    ans.push_back(pq.top().first);

    // slide the window across the array
    for (int i = k; i < arr.size(); i++) {
            // remove elements whose indices are out of the current window
            while (!pq.empty() && pq.top().second <= i - k) {
                pq.pop();
            }
            // push the current element (value, index)
            pq.push({ arr[i], i });
            // current window maximum
            ans.push_back(pq.top().first);
        
    }

    return ans;
}
int main() {
    vector<int> arr = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int k = 3;
    // example usage and print results
    vector<int> ans = slidingWindow(arr, k);

    for (int i : ans) {
        cout << i << " ";
    }
    return 0;
}