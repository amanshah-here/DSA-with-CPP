#include<iostream>
using namespace std;

int decimal(int n){

    int binum=n;
    int pow = 1;//power is currently 2^0=1
    int ans = 0;

    while(binum>0){

        int rem = binum % 10;
        ans += (rem * pow);//here we're multiplying the digit with 2^n
        binum /= 10;
        pow *= 2;//everytime power is updated it becomes 2^2 2^3 2^4...
    }
    cout << "decimal number:" << ans << endl;

    return 0;
}

int main()
{
    int n;
    cout << "enter binary number:";
    cin >> n;
    decimal(n);
    return 0;
}