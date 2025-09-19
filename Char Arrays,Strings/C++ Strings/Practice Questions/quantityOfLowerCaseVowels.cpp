#include<iostream>
#include<string>
using namespace std;

int lowerCaseVowel(string& str) {   //returns the count of total number of lower case vowels in the passed string
    int count = 0;

    for (char ch : str) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }

    return count;
}

int main() {
    string str;

    cout << "Enter a String: ";
    getline(cin, str);

    cout << "Total Number of LowerCase Vowels: " << lowerCaseVowel(str) << endl;

    return 0;
}