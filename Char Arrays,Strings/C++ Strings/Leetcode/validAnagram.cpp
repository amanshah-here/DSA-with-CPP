#include<iostream>
#include<string>
using namespace std;

bool validAnagram(string& str1, string& str2) {

    int arr[26] = { 0 };        //Array of 26 size to store the count of characters
    if (str1.length() != str2.length()) {
        return false;
    }

    for (int i = 0;i < str1.length(); i++) {    //traversing each element of str1 and updating its count in arr.

        arr[(str1[i] - 'a')]++;

    }

    for (int i = 0;i < str2.length(); i++) {    //traversing each element of str2 and matching the element and decrementing count.

        if (arr[(str2[i] - 'a')] == 0) {
            return false;
        }
        arr[(str2[i] - 'a')]--;

    }

    return true;
}

int main() {
    string str1="anagram";
    string str2="nagaram";

    cout << validAnagram(str1, str2);
    return ;
}