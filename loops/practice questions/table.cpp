#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "enter a number";
    cin >> n;
    cout << "\n TABLE OF " << n << " : " << endl;
    for (int i = 1; i <= 10; i++){

        cout << n << " x " << i << " = " << n * i << endl;
    }

    return 0;
}