#include<iostream>
#include<vector>
using namespace std;

int minCoins(vector<int>& coins, int V) {
    int ans = 0;    // Count of coins used

    // iterate from largest coin to smallest (greedy)
    for (int i = coins.size() - 1; i >= 0 && V > 0; i--) {
        // use as many coins of this denomination as possible
        if (coins[i] <= V) {
            ans += V / coins[i];    // adding the total number of current coins that can be used.
            V = V % coins[i];   // updating the current need of coins
        }
    }
    return ans;
}

int main() {
    vector<int> coins = { 1, 2, 5, 10, 20, 50, 100, 500, 2000 };
    int V = 590;

    cout << "Minimum coins to complete " << V << ": " << minCoins(coins, V) << endl;

    return 0;
}