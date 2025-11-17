#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Custom comparator for min heap based on soldier strength and row index
struct compare {
    bool operator () (pair<int, int>& p1, pair<int, int>& p2) {
        // If strength is equal, prioritize smaller row index
        if (p1.first == p2.first) return p1.second > p2.second;
        // Otherwise, prioritize smaller strength count
        return p1.first > p2.first;
    }
};


// Find k weakest soldiers based on strength (consecutive 1s from start)
vector<int> weakestSoldier(vector<vector<int>>& soldiers, int k) {
    // Store strength count and row index pairs
    vector<pair<int, int>> rows;

    // Count consecutive 1s from start of each row
    for (int i = 0; i < soldiers.size(); i++) {
        int count = 0;
        for (int j = 0; j < soldiers[i].size() && soldiers[i][j] == 1; j++) {
            count++;
        }

        rows.push_back({ count, i });
    }

    // Create min heap using custom comparator
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq(rows.begin(), rows.end());

    // Extract k weakest soldiers
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}


int main() {
    // Test case: 4x4 grid of soldiers
    vector<vector<int>> soldiers = { {1, 0, 0, 0},
                                     {1, 1, 1, 1},
                                     {1, 0, 0, 0},
                                     {1, 0, 0, 0} };
    int k = 3;

    // Get k weakest soldiers
    vector<int> ans = weakestSoldier(soldiers, k);

    // Print results
    for (int i : ans) {
        cout << "weakest soldiers: row->" << i << endl;
    }
    return 0;
}