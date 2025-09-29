#include<iostream>
#include<string>
#include<vector>
using namespace std;

int compression(vector<char> chars) {
    int idx = 0;
    for (int i = 0; i < chars.size(); i++) {
        int c = 0;
        char ch = chars[i];
        while (i < chars.size() && chars[i] == ch) {    //if the characters are repeated
            c++;    //increasing the count
            i++;
        }
        
        chars[idx++] = ch;
        if (c > 1) {    //if the count is greater than 1
            for (char digit : to_string(c)) {
                chars[idx++] = digit;   //storing the count as individual digits in the chars array.
            }
        }
        i--;
    }
    chars.resize(idx);  //removing any extra element remaining in the chars array.
    return idx; //returning the size of array now.
}

int main() {
    vector<char>chars = { 'a','a','b','b','b','c' };

    cout << compression(chars) << endl;
    return 0;
}