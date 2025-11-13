#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

// Car class to store car index and squared distance from origin
class Car {
public:
    int idx;        // Original index of the car in input array
    int distSq;     // Squared distance from origin (x^2 + y^2)

    Car(int idx, int distSq) {
        this->idx = idx;
        this->distSq = distSq;
    }

    // Comparator for max heap - returns true if current car is farther
    bool operator < (const Car& c) const {
        return this->distSq > c.distSq;
    }
};

// Returns k cars closest to origin (0, 0)
// Time Complexity: O(n + k*logn)
vector<pair<int, int>> nearbyCars(vector<pair<int, int>>& pos, int k) {
    vector<Car> cars;

    // Calculate squared distance for each car (avoids sqrt operation)
    for (int i = 0; i < pos.size(); i++) {
        int distSq = pos[i].first * pos[i].first + pos[i].second * pos[i].second;
        cars.push_back(Car(i, distSq));
    }

    // Build max heap from all cars
    priority_queue<Car> pq(cars.begin(), cars.end());

    // Extract k closest cars
    vector<pair<int, int>> ans;
    for (int i = 0; i < k; i++) {
        ans.push_back({ pos[pq.top().idx] });
        pq.pop();
    }
    return ans;
}

int main() {
    // Test data: car positions
    vector<pair<int, int>> cars;
    cars.push_back(make_pair(3, 3));
    cars.push_back(make_pair(5, -1));
    cars.push_back(make_pair(-2, 4));

    int k = 2;  // Find 2 nearest cars

    // Find and display k nearest cars
    vector<pair<int, int>> ans = nearbyCars(cars, k);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << ", " << ans[i].second << endl;
    }

    return 0;
}