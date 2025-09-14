#include<iostream>
using namespace std;

int main()
{
    int a = 10;
    float b = 100.26;

    int *ptr = &a;
    float *ptr2 = &b;
    cout << "address of a:" << ptr << endl;
    cout << "address of b:" << ptr2 << endl;
    return 0;
}