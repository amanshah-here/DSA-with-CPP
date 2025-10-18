#include<iostream>
#include<string>
#include<stack>
using namespace std;

// Check if the input string has valid matching parentheses/brackets/braces.
// Returns true when every opening symbol has a corresponding closing symbol
// in the correct order; false otherwise.
bool isValid(const string& str) {
    // Stack stores opening brackets encountered while scanning left-to-right
    stack<char> s;

    for (char ch : str) {
        // When we see an opening bracket, push it onto the stack
        if (ch == '[' || ch == '{' || ch == '(') {
            s.push(ch);
        }
        else {
            // If a closing bracket appears but stack is empty, it's invalid
            if (s.empty()) return false;

            // Check if the most recent opening bracket matches
            char last = s.top();
            s.pop();

            // If types don't match, the string is invalid
            if ((ch == ']' && last != '[') ||
                (ch == '}' && last != '{') ||
                (ch == ')' && last != '(')) {
                return false;
            }
        }
    }

    // If any unmatched opening brackets remain, it's invalid
    return s.empty();
}

int main() {
    // Example test cases
    string str = "({{[]}})";   // valid
    string str2 = "({][})]";   // invalid
    string str3 = "(){}[]";    // valid

    cout << isValid(str) << endl;   // expected: 1
    cout << isValid(str2) << endl;  // expected: 0
    cout << isValid(str3) << endl;  // expected: 1
     
    return 0;
}