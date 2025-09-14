#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter number of iteration:";
    cin >> n;

    // for upper part
    for (int i = 0; i < n;i++){
        
        // for 1st triangle
        for (int j = 0; j < i + 1;j++){
            cout << "*";
        }
        // for space
        for (int k = 0; k < 2 * (n - i) - 2;k++){
            cout << " ";
        }
        // for end triangle
        for (int l = 0; l < i + 1;l++){
            cout << "*";
        }
        cout << endl;
    }

    // for lower part
    for (int i = 0; i < n;i++){
        
        //for 1st triangle
        for (int j = 0; j < n - i;j++){
            cout << "*";
        }

        //for space
        for (int k = 0; k < 2 * i ;k++){
            cout << " ";
        }

        //for end triangle
        for (int l = n; l >= i+1;l--){
            cout << "*";
        }
        cout << endl;
    }
        return 0;
}