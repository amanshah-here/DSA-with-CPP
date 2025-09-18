#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char str[50];
    char str1[50] = "hello world";

    strcpy(str, str1); //! to copy one string into another
    cout << str << endl;

    return 0;
}