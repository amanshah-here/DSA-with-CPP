#include<iostream>
#include<string>
#include<stack>
using namespace std;

// decode:
// input: an encoded string using numbers and square brackets
// output: the fully decoded string
// Approach: iterate through the input and use two stacks:
// - num: holds multipliers (k values)
// - s: holds the previous built strings before encountering a '['
// We build the current substring in 'ans'. When we see a digit we accumulate
// it into 'n' (to handle multi-digit numbers). When we see '[', we push the
// current number and current answer onto their stacks and reset them. When we
// see ']', we pop the multiplier and previous string, and append the current
// substring repeated multiplier times to the previous string.
string decode(string str) {
    stack<int> num;       // stack to store repeat counts
    stack<string> s;      // stack to store previous strings

    int n = 0;            // current number being parsed (may be multi-digit)
    string ans;           // current working substring

    for (char ch : str) {
        if (isdigit(ch)) {
            n = n * 10 + (ch - '0');
        }
        else if (ch == '[') {
            // push the accumulated number and the current string
            // onto their respective stacks, then reset for the
            // new substring inside the brackets
            num.push(n);
            s.push(ans);

            n = 0;
            ans = "";
        }
        else if (ch == ']') {
            // on closing bracket, pop the repeat count and previous
            // string, then append the current substring 'temp' repeated
            // 'k' times to the previous string
            int k = num.top();
            num.pop();

            string temp = ans;      // substring inside the most recent brackets
            ans = s.top();          // previous string before those brackets
            s.pop();

            while (k-- > 0) {
                ans += temp;
            }
        }
        else {
            ans += ch;
        }
    }
    return ans;
}

// small test harness to demonstrate and smoke-test the decode function
int main() {
    // example cases from common problem statements
    string a = "3[a]2[bc]";        // expected: aaabcbc
    string b = "3[a2[c]]";        // expected: accaccacc
    string c = "2[abc]3[cd]ef";   // expected: abcabccdcdcdef

    cout << "decode(\"" << a << "\") = " << decode(a) << "\n";
    cout << "decode(\"" << b << "\") = " << decode(b) << "\n";
    cout << "decode(\"" << c << "\") = " << decode(c) << "\n";

        return 0;
}