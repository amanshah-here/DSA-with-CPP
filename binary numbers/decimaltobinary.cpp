#include<iostream>
using namespace std;

int main()
{
    int decnum;
    int rem;
    int ans = 0;
    int pow = 1;//power is currently 10^0=1

    cout << "enter a number:";
    cin >> decnum;

    while(decnum>0){

        rem = decnum % 2;
        decnum = decnum / 2;
        ans += (rem * pow);
        pow = pow * 10;//each time the power is incremented and become 10^2 10^3 10^4 ....
    }

    cout << "binary number:" << ans << endl;
    return 0;
}