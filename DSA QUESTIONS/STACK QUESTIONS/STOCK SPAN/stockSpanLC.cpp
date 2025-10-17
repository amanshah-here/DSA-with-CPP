#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class StockSpanner {
public:
    stack<int> s;          // Stack to store indices of days with higher prices
    vector<int> stock;     // Vector to store all stock prices

    StockSpanner() = default;

    int next(int price) {
        stock.push_back(price);  // Add current price to the stock vector

        // Pop indices from stack where price is less than or equal to current price
        while (!s.empty() && price >= stock[s.top()]) {
            s.pop();
        }
        // Calculate span: if stack empty, all previous days are included
        int span = s.empty() ? stock.size() : stock.size() - 1 - s.top();
        s.push(stock.size() - 1);  // Push current index (0-based) onto stack
        return span;
    }
};