#include<iostream>
using namespace std;

int main()
{
    int arr[5] = {12, 43, 575, 1, 2};
    int small = INT8_MAX;
    for (int i = 0; i < 5;i++){

        if(arr[i]<small){
            small = arr[i];
        }
    }
    cout << "smallest number:" << small << endl;
    return 0;

}