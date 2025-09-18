#include<iostream>
#include<string>
using namespace std;

int main() {
    string str = "cat";
    string str1 = "cat";
    string str2 = "abc";
    string str3 = "xyz";

    cout << (str == str1) << endl;
    cout << (str != str1) << endl;
    cout << (str2 < str3) << endl;
    cout << (str2 > str3) << endl;
    
    return 0;
}