#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;   // Ascending Order - end
}

int main() {
    vector<int> start = { 0, 1, 2 };
    vector<int> end = { 9, 2, 4 };

    vector<pair<int, int>> activity(3, make_pair(0, 0));
    for (int i = 0; i < 3; i++) {
        activity[i] = make_pair(start[i], end[i]);
    }

    for (int i = 0; i < activity.size(); i++) {
        cout << "A" << i << " : " << "(" << activity[i].first << ", " << activity[i].second << ")" << endl;
    }

    sort(activity.begin(), activity.end(), compare);
    cout << "-------------Sorted--------------\n";
    for (int i = 0; i < activity.size(); i++) {
        cout << "A" << i << " : " << "(" << activity[i].first << ", " << activity[i].second << ")" << endl;
    }
    return 0;
}