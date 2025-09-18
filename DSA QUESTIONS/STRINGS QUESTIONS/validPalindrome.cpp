#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string &s) {
    int len = s.length();
    int st = 0, end = len - 1;

    while (st <= end) {

        if (!isalnum(s.at(st))) {     //? skip non-aphanumeric value at start
            st++;
            continue;

        }if (!isalnum(s.at(end))) {   //? skip non-alphanumeric value at end
            end--;
            continue;
        }

        if (tolower(s.at(st++)) != tolower(s.at(end--))) {
            return false;
        }
    }
    return true;
}


int main() {
    string str;

    cout << "enter a string: ";
    getline(cin, str);

    if (isPalindrome(str)) {
        cout << str << " is a Palindrome." << endl;
    }
    else {
        cout << str << " isn't a Palindrome.";
    }

    return 0;
}