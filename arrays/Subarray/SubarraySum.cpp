#include<iostream>
using namespace std;

int printSubarrays(int arr[],int size){
    for (int start= 0; start < size;start++){
        for (int end = start; end < size;end++){
            int sum = 0;
            for (int i = start; i <= end;i++){
                sum += arr[i];
            }
            cout << sum;
            if(end != size-1){
                cout << " , ";
            }
        }
            cout << endl;
        }
        return 0;
}

int main(){
    int arr[] = {2,-3,6,-5,4,2};
    int size = sizeof(arr) / sizeof(int);
    printSubarrays(arr, size);

    return 0;
}