#include<iostream>
using namespace std;

int printSubarrays(int arr[],int size){
    for (int start= 0; start < size;start++){
        cout << "Starting point:" << start<<endl;
        cout << "Ending Point: ";
        for (int end = start; end < size;end++){
          cout <<end << " ";
        }
        cout << endl;
    }
    return 0;
}

int main(){
    int arr[] = {12, 231, 122, 32, 21, 2123};
    int size = sizeof(arr) / sizeof(int);
    printSubarrays(arr, size);

    return 0;
}