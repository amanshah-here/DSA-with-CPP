#include<iostream>
using namespace std;

int prime(int n){
    bool isprime = true;
    for (int i = 2; i < n;i++){

        if(n%i==0){
            isprime = false;
            break;
        }

    }
    if(isprime==true){
        cout << "number is prime\n";
    }
    else{
        cout << "number isn't prime\n";
    }

    return 0;
}
int main()
{
    int n;
    cout << "enter a number:";
    cin >> n;

    cout << prime(n) << endl;

    return 0;
}