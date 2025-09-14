#include<iostream>
using namespace std;

int main()
{
    int num;
    cout << "enter a number:\n" << endl;
    cin >> num;

    (num >= 0) ? cout << "number is +ve\n" : cout << "number is -ve\n";
    return 0;
}