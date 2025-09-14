#include<iostream>
using namespace std;

int main()
{
    int num;
    cout << "enter a number:\n";
    cin >> num;
    if(num%2==0){
        cout << "number is even\n";
    }else{
        cout << "number is odd\n";
    }
        return 0;
}