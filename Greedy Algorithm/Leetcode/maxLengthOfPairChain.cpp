#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Comparator: sort pairs by their second value (end)
bool compare(pair<int, int>& p1, pair<int, int>& p2) {
    return p1.second < p2.second;
}

// Greedy: after sorting by end, pick as many pairs as possible
int maxLength(vector<pair<int, int>>& pairs) {
    sort(pairs.begin(), pairs.end(), compare);

    int currEnd = pairs[0].second; // end of last chosen pair
    int length = 1; // at least one pair is chosen

    for (int i = 1; i < pairs.size(); i++) {
        // choose pair if its start is after current end
        if (pairs[i].first > currEnd) {
            length++;
            currEnd = pairs[i].second;
        }
    }
    return length;
}


int main() {
    // sample input
    vector<pair<int, int>> pairs = { make_pair(5,24), make_pair(39, 60), make_pair(5,28), make_pair(27,40), make_pair(50, 90) };

    cout << maxLength(pairs) << endl; // expected output: 3
    return 0;
}