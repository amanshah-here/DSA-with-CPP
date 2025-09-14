#include<iostream>
using namespace std;

int main(){

    int num;

    cout << "ENTER A NUMBER:";
    cin >> num;

    if(num == 0){
        cout << "NUMBER IS ZERO...." << endl;
    }else if(num > 0){
        cout << "NUMBER IS POSITIVE...." << endl;
    }else{
        cout << "NUMBER IS NEGATIVE...." << endl;
    }

    return 0;
}