#include<iostream>
using namespace std;

int main()
{
    double num;
    double fact = 1;

    cout << "enter a number:\n";
    cin >> num;

    for (double i = 1; i <= num;i++){
        fact = fact *i;
    }
    cout << "factorial of " << num << " : " << fact << endl;
    return 0;
}