#include <iostream>
#include <queue>
using namespace std;

// Custom comparator for the priority_queue (Min-Heap).
struct compare {
    bool operator() (pair<int, int>& p1, pair<int, int>& p2) {
        return (p1.first * p1.first + p1.second * p1.second)
            > (p2.first * p2.first + p2.second * p2.second);
    }
};

// nearbyCars: return the k nearest cars (points) to the origin.
vector<pair<int, int>> nearbyCars(vector<pair<int, int>>& cars, int k) {
    // priority_queue of points ordered by distance (smallest distance at top)
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

    // Push all car coordinates into the priority queue
    for (int i = 0; i < (int)cars.size(); i++) {
        pq.push(cars[i]);
    }

    vector<pair<int, int>> ans;

    // Extract the k closest points from the queue
    for (int i = 0; i < k && !pq.empty(); i++) {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}

int main() {
    // Example usage: three car coordinates
    vector<pair<int, int>> cars;
    cars.push_back(make_pair(3, 3));
    cars.push_back(make_pair(5, -1));
    cars.push_back(make_pair(-2, 4));

    int k = 2; // number of nearest cars to find

    // Get result and print
    vector<pair<int, int>> ans = nearbyCars(cars, k);
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i].first << ", " << ans[i].second << endl;
    }

    return 0;
}