#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Fractional Knapsack (Greedy)
// Given values and weights, take whole items or fractions to maximize value
// Time: O(n log n) for sorting, Space: O(n) for ratio array

//function for sorting the paired ratio vector in descending order
bool compare(pair<double, int> p1, pair<double, int> p2) {
    return p1.first > p2.first;
}

int fractionalKnapsack(vector<int>& value, vector<int>& weight, int capacity) {
    // store (value/weight ratio, original index)
    vector < pair<double, int>> ratio(value.size(), make_pair(0.0, 0));

    int ans = 0; // accumulated max value (may include fractional part)

    //calculating and adding the ratio of each index into the ratio vector along with the original index
    for (int i = 0; i < value.size(); i++) {
        double currRatio = value[i] / (double)weight[i];
        ratio[i] = make_pair(currRatio, i);
    }

    sort(ratio.begin(), ratio.end(), compare);  //sorting to get the most valuable at front.

    //now time to add the items into the knapsack.
    for (int i = 0; i < ratio.size(); i++) {
        int idx = ratio[i].second;

        // if whole item fits, take it
        if (weight[idx] <= capacity) {
            ans += value[idx];
            capacity -= weight[idx];
        }
        else {
            // otherwise take fraction of this item to fill capacity
            ans += ratio[i].first * capacity; // fractional value added
            capacity = 0;
            break; // knapsack is full
        }
    }

    return ans;
}

int main() {
    vector<int> value = { 60, 100, 120 };
    vector<int> weight = { 10, 20, 30 };
    int capacity = 50;

    cout << "Maximum Value: " << fractionalKnapsack(value, weight, capacity) << endl;
    return 0;
}