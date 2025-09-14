#include<iostream>
using namespace std;

int main()
{
    int n;
    char ch = 'A';

    cout << "enter the number of iteration:";
    cin >> n;

    for (int i = 0; i < n;i++)
    {
        for (int j = i; j >= 0;j--){
            cout <<char(ch + j) << " ";
        }
        cout << endl;
    }
}