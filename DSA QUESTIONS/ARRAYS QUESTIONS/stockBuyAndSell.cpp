#include<iostream>
using namespace std;

int stock(int *prices,int size){
    int maxProfit = 0;
    int bestBuy = prices[0];

    for (int i = 0; i < size; i++){
        if(prices[i] > bestBuy){
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    }

    return maxProfit;
}

int main(){
    int prices[] = {7, 1, 5, 3, 6, 4};
    int size = sizeof(prices) / sizeof(int);

    cout << " Maximum Profit Possible: " << stock(prices, size) << endl;

    return 0;
}