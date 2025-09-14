#include<iostream>
using namespace std;

int main(){

    int num1, num2;

    cout << "enter 1st number: ";
    cin >> num1;
    cout << "enter 2nd number: ";
    cin >> num2;

    if (num1 > num2){
        cout << num1 << " is greater" << endl;
    }else{
        cout << num2 << " is greater" << endl;
    }

    return 0;
}