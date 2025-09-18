#include<iostream>
#include<string>
using namespace std;

int main() {
    string str = "Hello World!";

    cout << str.substr(0, 5) << endl;   //? prints the substring of the str starting at index 0 upto size 4
    cout << str.substr(6, 6) << endl;   //? prints the substring of the str starting at index 6 upto size 6

    return 0;
}