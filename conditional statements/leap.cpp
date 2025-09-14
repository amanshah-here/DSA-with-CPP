#include<iostream>
using namespace std;

int main(){

    int year;
    cout << "ENTER THE YEAR:";
    cin >> year;

    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        cout << year << " IS LEAP YEAR...." << endl;
    }else{
        cout << year << " ISN'T A LEAP YEAR...." << endl;
    }

    return 0;
}