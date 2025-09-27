#include<iostream>
using namespace std;

void example() {    //here we have not declared the base case due to which the function will run infinitely leading to stack overflow.
    cout << "Function call\n";
    example();  //recursive call
}

int main() {
    example();
    return 0;
}