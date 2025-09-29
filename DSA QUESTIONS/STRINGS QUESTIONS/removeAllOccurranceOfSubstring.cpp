#include<iostream>
#include<string>
using namespace std;

string removeOccurrance(string str, string part) {
    while (str.find(part) != string::npos) {    //looping while the part is not found in str.

        str = str.erase(str.find(part), part.length()); //erasing the part from str.
    }
    return str;
}

int main() {
    string str = "abcxabcxabc";
    string part = "abc";

    cout << removeOccurrance(str, part);
    return 0;
}