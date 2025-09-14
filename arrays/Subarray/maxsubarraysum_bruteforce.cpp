#include<iostream>
using namespace std;

// bruteforce approach
// timecomplexity=O(n*n);
int maxSubarraySum(int *arr,int size){
    int maxSum = INT8_MIN;

    for (int strt = 0; strt < size;strt++){
        int currsum = 0;
        for (int end = strt; end < size;end++){
            currsum += arr[end];
            maxSum = max(currsum, maxSum);
        }
    }
    
    return maxSum;
}

int main(){
    int arr[] = {2,-3,6,-5,4,2};
    int size = sizeof(arr)/sizeof(int);

    cout << "maximum subarray sum: " <<maxSubarraySum(arr,size)<< endl;

    return 0;
}