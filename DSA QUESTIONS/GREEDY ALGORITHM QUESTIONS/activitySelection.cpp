#include<iostream>
#include<vector>
using namespace std;

// Return the maximum number of non-overlapping activities that can
// be scheduled. This uses the standard greedy approach which assumes
// activities are considered in non-decreasing order of finish time.
int maxActivity(vector<int>& start, vector<int>& end) {
    // Select the first activity by default
    int currEnd = end[0];
    int count = 1;

    // For each next activity, if its start time is >= the end time of
    // the last selected activity, select it and update currEnd.
    for (int i = 1; i < start.size(); i++) {
        if (start[i] >= currEnd) {
            count++;
            currEnd = end[i];
        }
    }
    return count;
}

int main() {
    // Example activity times (end times are sorted here)
    vector<int> start = { 1, 3, 0, 5, 8, 5 };
    vector<int> end = { 2, 4, 6, 7, 9, 9 };

    // Expected output for this example: 4
    cout << maxActivity(start, end) << endl;
    return 0;
}