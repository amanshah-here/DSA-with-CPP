#include<iostream>
using namespace std;

int palindrome(int n){
    int rem;
    int rev = 0;
    int n1 = n;
    // bool isPalin = true;

    while(n!=0){
        rem = n % 10;
        rev = rev * 10 + rem;
        n = n / 10;
    }
    if(rev == n1){
        return true;
    }else{
        return false;
    }
    return -1;
}

int main(){
    int n;
    cout << "enter a number: ";
    cin >> n;

    bool check=palindrome(n);
    if(check){
        cout << n << " is a palindrome." << endl;
    }else{
        cout << n << " isn't a palindrome.";
    }

    return 0;
}