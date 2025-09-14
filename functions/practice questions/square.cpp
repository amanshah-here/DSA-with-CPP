#include<iostream>
using namespace std;

int square(int a,int b){
    return (a * a) + (b * b) + (2 * a * b);
}

int main(){
    int a, b;
    cout << "enter value of a: ";
    cin >> a;
    cout << "enter value of b: ";
    cin >> b;
    cout << "a^2 + b^2 + 2ab : " << square(a, b) << endl;

    return 0;
}