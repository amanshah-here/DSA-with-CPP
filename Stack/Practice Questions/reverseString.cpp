#include<iostream>
#include<stack>
#include<string>
using namespace std;


//* function to reverse a string using Stack.
string reverseString(string s) {    //? TC:O(n) | SC: O(n) 
    stack<char> rev;    // stack to store the reverse.
    for (char ch : s) {
        rev.push(ch);
    }

    string ans; 
    while (!rev.empty()) {  // looping while the stck is empty.
        ans += rev.top();   // adding the top to ans;
        rev.pop();  // poping the top to get access of next character.
    }
    return ans; // returning the reversed string.
}



int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);  // taking a string as input from user

    cout <<"'"<< str <<"'"<< " when reversed: "<<reverseString(str);    // printing the reverse of the string.

    return 0;
}