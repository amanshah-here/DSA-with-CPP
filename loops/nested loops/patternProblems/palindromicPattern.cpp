#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "enter the no of iteration: ";
    cin >> n;

    for (int i = 1; i <= n ; i++)
    {
        //for spaces in first half
        for (int j = 1; j <= n-i; j++)
        {
            cout << " ";
        }
        //numbers in first half
        for (int j = i; j >= 1; j--){
            cout << j;
        }
        //numbers in 2nd half
        for (int j = 2; j <= i;j++){
            cout << j;
        }
        cout << endl;
    }

    return 0;
}