#include<iostream>
#include<cmath>
using namespace std;

int main(){

    int num;

    cout << "enter a number : ";
    cin >> num;

    for (int i = 2; i <= num; i++){
        bool isPrime = true;
        for (int j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime)
            cout << i << " IS A PRIME NUMBER " << endl;
        else
            cout << i << " ISN'T A PRIME NUMBER " << endl;
    }
    return 0;
}