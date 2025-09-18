#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char str[20] = "Hello";
    char str1[10] = "World";

    strcat(str, str1); //! it concatenates 2 strings and update it to the 1st one

    cout << str << endl;
}