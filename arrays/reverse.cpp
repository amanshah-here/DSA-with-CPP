#include<iostream>
using namespace std;

int reverse(int *arr, int size){
    int strt = 0;
    int end = (size - 1);

    while(strt<end){
    swap(arr[strt], arr[end]);
    strt++;
    end--;
    }
    return 0;
} 
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = 8;

    reverse(arr, size);

    for (int i = 0; i < size ;i++){
        cout << arr[i] << ",";
    }

        return 0;

}