#include<iostream>
using namespace std;

int swapping(int arr[],int sz){
    int max=INT8_MIN, min=INT8_MAX;
    for (int i = 0; i < sz ;i++){
        if(arr[i]<min){
            min = arr[i];
        }
        if(arr[i]>max){
            max = arr[i];
        }
    }
    cout << "before swap\n"
         << "max:" << max << "  min:" << min << endl;

    swap(max, min);
    cout << "after swap:" << "max:" << max << "  min:" << min << endl;
}
int main()
{
    int arr[] = {31, 62, 67, 34, 300, 3};
    int sz = 6;
    swapping(arr, sz);
    return 0;
}