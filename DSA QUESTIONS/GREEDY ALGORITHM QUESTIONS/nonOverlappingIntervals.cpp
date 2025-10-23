#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // sort intervals by their end time (smallest end first)
    sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
        return a[1] < b[1];
    });

    // track end of the current non-overlapping interval
    int currEnd = intervals[0][1];
    // count of intervals we keep (non-overlapping)
    int count = 1;

    // go through remaining intervals and pick non-overlapping ones
    for (int i = 1; i < intervals.size(); i++) {
        // if this interval starts after or at current end, it's not overlapping
        if (intervals[i][0] >= currEnd) {
            count++;
            currEnd = intervals[i][1];
        }
    }
    // number to remove = total intervals - intervals kept
    return intervals.size() - count;
}

int main() {
    vector<vector<int>> intervals = { {1,2} ,{2,3},{3,4},{1,3} };

    // sample input and output
    cout << "minimum no of intervals needed to remove: "
         << eraseOverlapIntervals(intervals) << endl;

    return 0;
}