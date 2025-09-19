#include<iostream>
#include<vector>
using namespace std;

int maxWater(vector<int>& height){

    int maxWater = 0;
    int left = 0;
    int right = height.size() - 1;

    while(left<right){

        int width = right - left;
        int ht = min(height[left], height[right]);
        int currWater = width * ht;
        maxWater = max(maxWater, currWater);
        height[left] < height[right] ? left++ : right--;
    }
    return maxWater;
}

int main(){
    vector<int> height = {1, 8, 6, 3, 5, 4, 8, 3, 7};
    cout << "maximum water in container:" << maxWater(height);
    return 0;
}