#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// Find total number of subarrays with sum equal to k using prefix sum technique
int KsumSubarray(vector<int>& arr, int k) {
    unordered_map<int, int> m; // Hash map to store prefix sum frequencies
    m[0] = 1; // Base case: empty prefix has sum 0
    int count = 0; // Counter for subarrays with target sum
    int sum = 0; // Running prefix sum

    for (int j = 0; j < arr.size(); j++) {
        sum += arr[j]; // Add current element to prefix sum
        // If (sum - k) exists, we found subarrays ending at current index
        if (m.count(sum - k)) {
            count += m[sum - k];
        }
        if (m.count(sum)) {
            m[sum]++; // Increment frequency of current prefix sum
        }
        else {
            m[sum] = 1; // Add new prefix sum to map
        }
    }
    return count;
}

int main() {
    vector<int> arr = { 10, 2, -2, -20, 10 }; // Test array
    int k = -10; // Target sum

    cout << "Total subarray with sum: " << KsumSubarray(arr, k) << endl;

    return 0;
}