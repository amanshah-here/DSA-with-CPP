#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isDuplicate(string str) {
    stack<char> s; // stack to keep track of characters and parentheses

    for (char ch : str) {
        // Push everything except closing parenthesis
        if (ch != ')') {
            s.push(ch);
        }
        else {
            // When we encounter a closing parenthesis, if the top of the stack is an opening parenthesis then there were no characters between '(' and ')' -> duplicate parentheses.
            if (s.top() == '(') return true;

            // Otherwise, pop until the matching '(' is removed. This skips
            // the contents inside the current pair of parentheses.
            while (s.top() != '(') {
                s.pop();
            }
            s.pop(); // pop the matching '('
        }
    }
    return false; // no duplicates found
}

int main() {
    // Example inputs
    string s1 = "((2 + 4) - (12 * 2))"; // no duplicate parentheses
    string s2 = "(((x + y)))";         // duplicate parentheses around x + y

    // Prints: 0 (false) then 1 (true)
    cout << isDuplicate(s1) << endl;
    cout << isDuplicate(s2) << endl;

    return 0;
}