#include<iostream>
using namespace std;

int main()
{
    int i = 1;
    int num;
    cout << "enter a number:\n";
    cin >> num;

    do{
        cout << i << " ";
        i++;
    } while (i <= num);
    return 0;
}