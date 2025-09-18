#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char str[10] = "Hello";
    char str1[10] = "Hello";

    cout << strcmp(str, str1) << endl; //todo: prints 0 when both the string have same value

    char str2[10] = "abc";
    char str3[10] = "xyz";

    cout << strcmp(str2, str3) << endl; //todo: prints any negative value if 2nd string is bigger in terms of ascii value

    char str4[10] = "xyz";
    char str5[10] = "abc";

    cout << strcmp(str4, str5) << endl;//todo: prints any positive value if 1st string is bigger in terms of ascii value

    return 0;
}