#include<iostream>
using namespace std;

int largest(int a, int b, int c){
    
    if(a > b && a > c){
        return a;
    }else if(b > a && b > c){
        return b;
    }else{
        return c;
    }

    return -1;
}

int main(){
    int a, b, c;
    cout << "enter 1st number: ";
    cin >> a;
    cout << "enter 2nd number: ";
    cin >> b;
    cout << "enter 3rd number: ";
    cin >> c;

    cout << largest(a, b, c) << " is the largest." << endl;

    return 0;
}