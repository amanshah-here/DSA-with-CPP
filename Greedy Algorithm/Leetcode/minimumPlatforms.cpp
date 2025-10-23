#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Compute minimum number of platforms required at a station
// given arrival times (arr) and departure times (dep).
// Approach: sort both lists and use two pointers to simulate
// trains coming and leaving, tracking how many are at the
// station at the same time.
int minPlatform(vector<int>& arr, vector<int>& dep) {

    // sort arrival and departure times
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    // ptr1 -> index for next arrival, ptr2 -> index for next departure
    int ptr1 = 0, ptr2 = 0;
    // currTrain counts trains currently at the station
    int currTrain = 0;
    // platform stores the maximum simultaneous trains seen
    int platform = 0;

    // walk through all arrivals
    while (ptr1 < arr.size()) {
        // if next train arrives before or at the same time as the
        // earliest departure, we need an extra platform
        if (arr[ptr1] <= dep[ptr2]) {
            currTrain++;
            platform = max(platform, currTrain);
            ptr1++;
        }
        else {
            // otherwise one train has departed freeing a platform
            currTrain--;
            ptr2++;

        }
    }
    return platform;
}

int main() {
    // example input: fill these with times in same units (e.g., minutes or HHMM)
    vector<int> arrival = { 900, 940, 950, 1100, 1500, 1800 };
    vector<int> departure = { 910, 1200, 1120, 1130, 1900, 2000 };

    // print result (will be 0 until you provide times above)
    cout << "Minimum platform needed: " << minPlatform(arrival, departure) << endl;
    return 0;
}