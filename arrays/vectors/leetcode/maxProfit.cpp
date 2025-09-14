#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices){
    int maxProfit = 0;
    int bestBuy = prices[0];

    for (int i = 0; i < prices.size();i++){
        if(prices[i]>bestBuy){
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    }
    return maxProfit;
}

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "maximum possible profit:" << maxProfit(prices);

    return 0;
}