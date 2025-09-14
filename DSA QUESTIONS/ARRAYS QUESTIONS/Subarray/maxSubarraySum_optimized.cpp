#include<iostream>
using namespace std;

int maxSubArraySum_optimized(int *arr,int size){
    int maxSum = INT8_MIN;
    
    for (int start = 0; start < size; start++){
        int currSum = 0;    //! here we add the next element of the array to the same currSum and then compare it to maxSum
        for (int end = start; end < size; end++){
            currSum += arr[end];
            maxSum = max(currSum, maxSum);
        }
    }
    return maxSum;
}

int main(){
    int arr[] = {2, -3, 6, -5, 4, 2};
    int size = sizeof(arr) / sizeof(int);

    cout << "Maximum Subarray Sum: " << maxSubArraySum_optimized(arr, size) << endl;

    return 0;
}