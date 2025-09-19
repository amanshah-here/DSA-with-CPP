#include<iostream>
#include<string>
using namespace std;

bool swapAndCheck(string str, string str1) {    //Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false
    if (str.length() != str1.length()) {
        return false;
    }
    if (str == str1) {
        return true;
    }

    string check = str1;
    int st = 0, end = str.length() - 1;

    while (st <= end) {
        swap(check.at(st), check.at(end));

        if (check == str) {
            return true;
        }
        check = str1;

        st++;
        end--;
    }
    return false;
}

int main() {
    string str;
    string str1;

    cout << "Enter Main String : ";
    getline(cin, str);

    cout << "Enter Distorted String : ";
    getline(cin, str1);

    if (swapAndCheck) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}