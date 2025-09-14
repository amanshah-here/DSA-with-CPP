#include<iostream>
using namespace std;

int main()
{
    int age;
    cout << "enter your age:\n";
    cin >> age;
    if(age>=18)
    {
        cout << "user can vote\n";
    }else{
        cout << "user cannot vote\n";
    }
    return 0;
}