#include<iostream>
using namespace std;

int sum(int arr[],int sz)
{
    int sum = 0;
    for (int i = 0; i < sz - 1;i++){
        sum = sum + arr[i];
    }
    return sum;
}

int product(int arr[],int sz){

    int product = 1;
    for (int i = 0; i < sz - 1;i++){

        product = product * arr[i];
    }
    return product;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int sz = 7;
    cout << "sum of the elements of array:" << sum(arr, sz) << endl;
    ;
    cout << "product of the elements of array:" << product(arr, sz) << endl;
    return 0;

}