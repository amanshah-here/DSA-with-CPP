#include<iostream>
#include<cstring>
using namespace std;

void upperCase(char* str) {
    int len = strlen(str);

    cout << "Converted String from 1st Function: ";
    for (int i = 0; i < len; i++) {
        cout << char(toupper(str[i]));

    }
}

void upperCase2(char* str) {
    int len = strlen(str);

    cout << "Converted String from 2nd Function: ";
    for (int i = 0; i < len; i++) {

        if (str[i] == ' ') {

            cout << str[i];

        }
        else if ('A' <= str[i] && str[i] <= 'Z') {

            cout << str[i];

        }
        else {
            cout << char((str[i] - 'a') + 'A');

        }
    }
}

int main() {
    char str[50];

    cout << "Input a String: ";
    cin.getline(str, 50, '.');

    upperCase(str);
    cout << endl;
    upperCase2(str);

    return 0;
}