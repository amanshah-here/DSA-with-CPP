#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(int n) {
    string str = to_string(n);
    int left = 0;
    int right = str.length() - 1;

    while (left <= right) {
        if (str[left] != str[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    int n;
    cout << "Enter a Number: ";
    cin >> n;

    isPalindrome(n) ? cout << "True" : cout<<"False";
    return 0;
}