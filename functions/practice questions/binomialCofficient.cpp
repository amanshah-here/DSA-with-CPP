#include<iostream>
using namespace std;

int fact(int n){
    int fact = 1;
    for (int i = 1; i <= n; i++){
        fact *= i;
    }

    return fact;
}

int BinCoff(int n,int r){
    int nCr;

    nCr = fact(n) / (fact(r) * fact(n - r));
    return nCr;
}

int main(){
    int n, r;

    cout << "enter the value of N: ";
    cin >> n;

    cout << "enter the value of R: ";
    cin >> r;

    cout << "binomial cofficient: " << BinCoff(n, r) << endl;

    return 0;
}