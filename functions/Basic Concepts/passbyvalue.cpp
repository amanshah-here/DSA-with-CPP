#include<iostream>
using namespace std;

int sum(int a,int b){
    a = a + 10;
    b = b + 10;
    return a + b;
}
int main()
{
    int x = 5;
    int y = 5;
    cout << "sum:" << sum(x, y) << endl;

    cout << "x :" << x << endl; // any changes made to the variable in the calling function doesn't reflect into the actual variable in the main fumction
    cout << "y:" << y << endl;

    return 0;
}