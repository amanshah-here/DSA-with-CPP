#include<iostream>
using namespace std;

int main()
{
    int arr[5];
    int largest = INT8_MIN;
    for (int i = 0; i < 5;i++){
        cout << "enter " << i + 1 << " number:";
        cin >> arr[i];
    }
    for (int i = 0; i < 5; i++ ){

        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    cout << "largest number:" << largest << endl;
    return 0;

}