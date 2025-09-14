#include<iostream>
using namespace std;

int main()
{
    char ch;
    cout << "enter a character:\n";
    cin >> ch;

    if(ch>='a' && ch<='z')
    {
        cout << "character is lowercase\n";
    }
    else if(ch>='A' && ch<='Z')
    {
        cout << "character is uppercase\n";
    }
    else{
        cout << "character isn't an alphabet\n";
    }
    return 0;
}