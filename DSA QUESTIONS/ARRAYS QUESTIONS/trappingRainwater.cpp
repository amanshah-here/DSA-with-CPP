#include<iostream>
using namespace std;

int maxWater(int *height,int size){
    int leftMax[size], rightMax[size];
    leftMax[0] = height[0];
    rightMax[size - 1] = height[size - 1];

    for (int i = 1; i < size; i++){
        leftMax[i] = max(leftMax[i-1], height[i]);
        
    }
    
    for (int i = size - 2;i >=0; i--){
        rightMax[i] = max(rightMax[i+1], height[i]);
        
    }
    
    int waterTrapped = 0;
    for (int i = 0; i < size;i++){
        int currWater = min(leftMax[i], rightMax[i]) - height[i];

        if(currWater>0){
            waterTrapped += currWater;
        }
    }
        return waterTrapped;
}

int main(){
    int height[] = {4, 2, 0, 6, 3, 2, 5};
    int size = sizeof(height) / sizeof(int);
    cout << "Rain Water Trapped: " << maxWater(height, size) << endl;

    return 0;
}