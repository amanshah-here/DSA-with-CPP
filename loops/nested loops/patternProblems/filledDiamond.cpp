#include<iostream>
using namespace std;


int main(){
    int n;

    cout << "enter no of iteration: ";
    cin >> n;

    for (int i = 1; i <= n; i++){
        
        //space for upper 1st half
        for (int j = 1; j <= n - i + 1;j++){
            cout << " ";
        }
        //star for upper 1st half
        for (int j = 1; j <= i; j++){
            cout << "*";
        }
        //star for upper 2nd half
        for (int j = 1; j <= i - 1;j++){
            cout << "*";
        }

            cout << endl;
    }
    //lower loop
    for (int i = 1; i <= n;i++){
        //space for lower first half
        for (int j= 1; j <= i;j++){
            cout << " ";
        }
        //star for lower 1st half
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "*";
        }
        //star for lower 2nd half
        for (int j = 1; j <= n-i; j++){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}