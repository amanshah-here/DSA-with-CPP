#include<iostream>
using namespace std;

//recursive function:- when a function calls itself repeatedly.
void func(int n) {
    if (n == 0) return; //base case
    cout << "Hello World\n";
    func(n - 1);    //recursive call.
}

int main() {
    func(5);
    return 0;
}