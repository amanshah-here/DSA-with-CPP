#include<iostream>
using namespace std;

int prime(int n){
    bool isprime = true;
    if(n<2){

        isprime = false;
        cout << n << endl;
    }

    for (int i = 2; i <= n;i++){

        for (int j = 2; j < i/2; j++)
        {

            if (i % j == 0)
            {
                isprime=false;
                break;
            }
             
        }

                if(isprime==true){
                    cout << i << " " << endl;
                }
    }
    return 0;
}

int main()
{
    int n;
    cout << "enter a number:";
    cin >> n;

    cout << prime(n) << endl;

    return 0;
}