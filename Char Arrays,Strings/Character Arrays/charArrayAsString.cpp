#include<iostream>
using namespace std;

int main(){
    char str[5] = {'h', 'e', 'l', 'l', 'o'};
    char str2[11] = {'h', 'e', 'l', 'l', 'o', ' ', 'a', 'm', 'a', 'n', '\0 '};

    cout << str << endl;
    cout << str2 << endl;

    return 0;
}