#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// Problem: Stock Span
// Given daily stock prices, for each day i compute the "span" —
// the maximum number of consecutive days up to i (including i)
// for which the price was less than or equal to price[i].
//
// Example:
// input:  {100, 80, 60, 70, 60, 85, 100}
// output: 1 1 1 2 1 5 7
//
// Algorithm (using a stack of indices):
// - Maintain a stack of indices of days with strictly decreasing prices
//   (stack top has the most recent day with price > current sequence).
// - For each day i, pop indices from the stack while stock[i] >= stock[top].
//   This removes days that are "covered" by the current day's span.
// - If the stack becomes empty, the span is (i+1) since no previous greater
//   element exists. Otherwise, span = i - stack.top() (distance from the
//   previous greater element).
// Complexity: O(n) time (each index pushed/popped at most once), O(n) extra space.

void stockSpan(vector<int> stock, vector<int>& span) {
    // stack will store indices of days
    stack<int> s;

    // first day always has span = 1
    s.push(0);
    span[0] = 1;

    // process remaining days
    for (int i = 1; i < stock.size(); i++) {
        // Pop indices while current price is greater than or equal to
        // the price at indices stored on the stack. Those days are
        // included in current span and no longer needed.
        while (!s.empty() && stock[i] >= stock[s.top()]) {
            s.pop();
        }

        // If stack is empty, no previous higher price exists, so span = i+1
        if (s.empty()) {
            span[i] = i + 1;
        }
        else {
            // previous higher price index
            int prevHigh = s.top();
            // span is difference between current day and previous higher day
            span[i] = i - prevHigh;
        }

        // push current day index onto stack for future days
        s.push(i);
    }

    // Output the spans (space separated)
    for (int val : span) {
        cout << val << " ";
    }
}

int main() {
    vector<int> stock = { 100, 80, 60, 70, 60, 85, 100 };
    vector<int>span(stock.size(), 0);

    stockSpan(stock, span);


    cout << endl;
    return 0;
}