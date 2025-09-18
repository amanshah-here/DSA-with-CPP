#include<iostream>
#include<string>
using namespace std;

int main() {
    string str = "Hello!";

    cout << str.at(0) << endl;  //? prints the value at index 0
    cout << str.at(3) << endl;  //? prints the value at index 3
    cout << str.at(5) << endl;  //? prints the value at index 5

    return 0;
}