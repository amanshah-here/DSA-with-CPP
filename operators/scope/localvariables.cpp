#include<iostream>
using namespace std;

int main()
{
    int a = 4;
    int b = 5;
    if(a<b){

        int x = 4;
        cout << x << endl;

    }
    // cout << x; x cannot be accessed outside if block
    for (int i = 0; i < 5;i++){
        
          cout << i << endl;
        
    }
    // cout << i << endl; i cannot be accessed outside the loop

}