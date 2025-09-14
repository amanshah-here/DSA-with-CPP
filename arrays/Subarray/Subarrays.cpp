#include<iostream>
using namespace std;

int printSubarrays(int arr[],int size){
    for (int start= 0; start < size;start++){
        for (int end = start; end < size;end++){
            cout << "( ";
            for (int i = start; i <= end;i++){
                cout << arr[i];
                if(i != end){
                    cout << ",";
                }
            }
            cout << " )";
            if(end !=size-1){
            cout << " , ";
            }
        }
        cout << endl;
    }
    return 0;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(int);
    printSubarrays(arr, size);

    return 0;
}