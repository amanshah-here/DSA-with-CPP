#include<iostream>
using namespace std;

int maxSubArraySum_kadane(int *arr,int size){
    int currSum = 0;
    int maxSum = INT8_MIN;

    for (int i = 0; i < size; i++){
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if(currSum < 0){
            currSum = 0;
        }
    }
    return maxSum;
}

int main(){
    int arr[] = {2, -3, 6, -5, 4, 2};
    int size = sizeof(arr) / sizeof(int);

    cout << "Maximum SubArray Sum: " << maxSubArraySum_kadane(arr, size) << endl;

    return 0;
}