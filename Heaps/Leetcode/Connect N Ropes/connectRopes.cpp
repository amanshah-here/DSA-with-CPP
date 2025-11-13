#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Function to calculate minimum cost to connect all ropes
int connectRopes(vector<int>& lengths) {
    // Create a min-heap and insert all rope lengths
    priority_queue<int, vector<int>, greater<int>> pq(lengths.begin(), lengths.end());

    int cost = 0;
    // Keep connecting two smallest ropes until one rope remains
    while (pq.size() > 1) {
        // Extract two smallest ropes
        int min1 = pq.top();
        pq.pop();

        int min2 = pq.top();
        pq.pop();

        // Connect the two ropes and add cost to total
        int currCost = min1 + min2;
        pq.push(currCost);

        cost += currCost;
    }
    return cost;
}

int main() {
    // Test case: ropes with lengths 4, 3, 2, 6
    vector<int> lengths = { 4, 3, 2, 6 };

    // Calculate minimum cost to connect all ropes
    int ans = connectRopes(lengths);

    // Output the result
    cout << "Cost: " << ans << endl;

    return 0;
}