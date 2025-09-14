#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    bool isPrime = true;
    cout << "enter a number: ";
    cin >> n;

    for (int i = 2; i < sqrt(n); i++){

        if(n % i == 0){
            isPrime = false;
            break;
        }
    }
     if(isPrime)
        cout << n << " is a prime number" << endl;
    else
        cout << n << " isn't a prime number" << endl;
        
    return 0;
}