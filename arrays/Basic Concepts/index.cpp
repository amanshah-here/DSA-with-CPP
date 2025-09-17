#include<iostream>
using namespace std;

int main()
{
    int arr[5];
    int largest = INT8_MIN;
    int index;
    for (int i = 0; i < 5;i++){
        cout << "enter " << i + 1 << " number:";
        cin >> arr[i];
    }
    for (int i = 0; i < 5; i++ ){

        if(arr[i]>largest){
            largest = arr[i];
            index = i;
        }
    }
    cout << "largest number:" << largest << endl;
    cout << "its's index:" << index << endl;
    return 0;

}