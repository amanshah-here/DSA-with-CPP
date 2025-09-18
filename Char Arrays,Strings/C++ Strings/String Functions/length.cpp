#include<iostream>
#include<string>
using namespace std;

int main() {
    string str;

    cout << "Enter a String : ";
    getline(cin, str);

    cout << "Length : " << str.length(); //? prints the length of the string

    return 0;
}