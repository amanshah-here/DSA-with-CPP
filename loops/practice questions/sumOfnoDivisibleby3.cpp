#include<iostream>
using namespace std;

int main()
{
    int num;
    int sum = 0;

    cout << "enter a number:\n";
    cin >> num;
    for (int i = 1; i <= num;i++){
        if(i%3==0)
        {
            sum = sum + i;
        }
    }
    cout << "some of the numbers divisble by 3 is:" << sum << endl;
    return 0;
}