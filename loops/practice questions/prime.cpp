#include<iostream>
using namespace std;

int main()
{
    bool isprime = true;
    int num;
    cout << "enter a number:\n";
    cin >> num;

    for (int i = 2; i <= num - 1;i++){
        if(num%i==0){
            isprime = false;
            break;
        }
    }
    if(isprime==false){
        cout << "number is not prime\n";
    }
    else{
        cout << "number is prime\n";
    }
    return 0;
}