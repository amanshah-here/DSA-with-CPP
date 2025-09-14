#include<iostream>
using namespace std;
int linearSearch(int arr[],int n,int size){

    for (int i = 0; i < size;i++){

        if(arr[i]==n){
            cout << n << " is found at index:" << i << endl;
            break;
        }
    }
    return 0;
}
int main()
{
    int arr[] = {4, 2, 7, 1, 8, 2, 5};
    int n = 7;
    linearSearch(arr, n, 7);

    return 0;

}