#include<iostream>
using namespace std;

int function(int (*arr)[4], int m,int n)
{
    cout << "0th row ptr : " << arr << endl;
    cout << "1st row ptr : " << arr + 1 << endl;
    cout << "2nd row ptr : " << arr + 2 << endl;
    return 0;
}

int function2(int arr[][4], int m,int n)
{
    cout << "0th row ptr : " << arr << endl;
    cout << "1st row ptr : " << arr + 1 << endl;
    cout << "2nd row ptr : " << arr + 2 << endl;
    
    return 0;
}

int main(){
    int arr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int m = 4;
    int n = 4;

    function(arr, m, n);
    cout << endl;
    function2(arr, m, n);

    return 0;
}