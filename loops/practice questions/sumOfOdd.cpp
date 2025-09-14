#include<iostream>
using namespace std;

int main()
{
    int sum = 0;
    int num;
    cout << "enter a number:\n";
    cin >> num;

    for (int i = 1; i <= num; i++){//this will print sum of odd numbers from 1 to n
        if (i % 2 != 0){
            sum = sum + i;
        }
    }
    cout << "sum: " << sum << endl;
    return 0;
}