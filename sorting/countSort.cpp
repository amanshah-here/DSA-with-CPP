#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int>& arr,int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

int countSort(vector<int>& arr,int size){
    int minVal = INT8_MAX, maxVal = INT8_MIN;

    // Find min and max values
    for (int i = 0; i < size; i++){
        minVal = min(minVal , arr[i]);
        maxVal = max(maxVal, arr[i]);
        
    }

    vector<int> freq(maxVal + 1,0);

    // Count frequencies
    for (int i = 0; i <size;i++){
        freq[arr[i]]++;
    }

    // Reconstruct sorted array
    for (int i = minVal,j = 0; i <= maxVal; i++)
    {
        while(freq[i] > 0)
        {
            arr[j++] = i;
            freq[i]--;
        }
    }

    printArray(arr,size);
}   

int main(){
    vector<int> arr = {1, 4, 1, 3, 2, 7, 8, 4, 3, 7};
    int size = arr.size();
    countSort(arr,size);

    return 0;
}