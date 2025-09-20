#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {

    int left = 0, right = height.size() - 1;
    int maxWater = 0;

    while (left < right) {

        int width = right - left;   //width of the current rectanglar container.
        int ht = min(height.at(left), height.at(right));   //height of the current rectangular container.

        int currWater = width * ht;     //currwater is basically area of the rectangular container.

        maxWater = max(maxWater, currWater);    //updating the maxWater with the maximum between curr and before.

        height.at(left) < height.at(right) ? left++ : right--; //updating the left or right based on condition.
    }

    return maxWater;
}

int main() {
    vector<int> height = { 1,8,6,2,5,4,8,3,7 };

    cout << "Maximum possible water in container: " << maxArea(height) << endl;

    return 0;
}