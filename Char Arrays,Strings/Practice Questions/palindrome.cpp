#include<iostream>
#include<cstring>
using namespace std;



bool is_palindrome(char* str) {

    int len = strlen(str);
    int st = 0, end = len - 1;
    while (st <= end) {
        if (str[st++] == str[end--]) {
            continue;
        }
        else {
            return false;
        }
    }
}


int main() {
    char str[50];

    cout << "Enter a String: ";
    cin.getline(str, 50);

    if (is_palindrome(str)) {
        cout << str << " is a Palindrome." << endl;
    }
    else {
        cout << str << " isn't a Palindrome." << endl;
    }

    return 0;
}