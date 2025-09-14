#include<iostream>
using namespace std;

int oddeven(int n){

    if(n % 2 == 0)
        cout << n << " is even." << endl;
    else
        cout << n << " is odd." << endl;
    return 0;
}

int main(){
    int n;
    cout << "enter a number: ";
    cin >> n;
    oddeven(n);

    return 0;
}