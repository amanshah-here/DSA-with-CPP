#include<iostream>
using namespace std;

int product(int a, int b){
    int prod = a * b;
    return prod;
}

int main(){
    int a, b;
    cout << "enter 1st number: ";
    cin >> a;
    cout << "enter 2nd number: ";
    cin >> b;

    cout << "product :" << product(a, b) << endl;

    return 0;
}