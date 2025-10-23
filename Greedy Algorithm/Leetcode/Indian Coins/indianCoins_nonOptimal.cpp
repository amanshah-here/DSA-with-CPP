#include<iostream>
#include<vector>
using namespace std;

int minCoins(vector<int>& coins, int V) {
    // Count of coins used
    int count = 0;

    // Iterate from largest coin to smallest (greedy approach).
    // NOTE: This implementation assumes `coins` is sorted in ascending order.
    // The loop index starts at coins.size() - 1 and decrements until 0.
    for (int i = coins.size(); i >= 0 && V > 0; i--) {
        // Use as many coins of denomination coins[i] as possible
        while (coins[i] <= V) {
            count++;
            // Print the coin chosen (matches some problem output formats)
            cout << coins[i] << " ";
            V -= coins[i];
        }
    }

    cout << endl; // newline after listing chosen coins
    return count;
}

int main() {
    vector<int> coins = { 1, 2, 5, 10, 20, 50, 100, 500, 2000 };
    int V = 590;

    cout << minCoins(coins, V) << endl;

    return 0;
}