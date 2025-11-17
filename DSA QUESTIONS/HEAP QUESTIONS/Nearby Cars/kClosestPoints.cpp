#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Custom comparator for min-heap based on distance from origin
struct compare {
    bool operator () (vector<int>& p1, vector<int>& p2) {
        // Compare squared distances to order points by proximity
        return (p1[0] * p1[0] + p1[1] * p1[1]) >
            (p2[0] * p2[0] + p2[1] * p2[1]);
    }
};


// Find k closest points to origin using min-heap
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // Create min-heap using custom comparator
    priority_queue<vector<int>, vector<vector<int>>, compare> pq(points.begin(), points.end());

    // Extract k closest points
    vector<vector<int>> ans;
    for (int i = 0; i < k; i++) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main() {
    // Initialize list of car coordinates
    vector<vector<int>> cars;

    // Add sample car positions
    cars.push_back({ 3, 3 });
    cars.push_back({ 5, -1 });
    cars.push_back({ -2, 4 });

    // Find 2 closest cars
    int k = 2;

    // Get k closest points
    vector<vector<int>> ans = kClosest(cars, k);

    // Print the result
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << ", " << ans[i][1] << endl;
    }

    return 0;
}