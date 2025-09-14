#include<iostream>
using namespace std;

int reverse(int n){

    int rem;
    int rev=0;
    
    while(n>0){

        rem = n % 10;
        rev = rev * 10 + rem;
        n = n / 10;
    }
    // cout << rev;
    return rev;
}

int main()
{
    int n;
    cout << "enter a number:";
    cin >> n;

    cout << "reversed number:" << reverse(n) << endl;
   
    return 0;

}