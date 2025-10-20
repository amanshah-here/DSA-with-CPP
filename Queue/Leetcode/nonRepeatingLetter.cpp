#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

// Return a string representing the first non-repeating character
// at each step while scanning the input string from left to right.
string FirstNonRepeated(string str) {
    vector<int> freq(26, 0);
    queue<char> q;
    string ans;

    for (char ch : str) {

        // push current char into queue and update frequency
        q.push(ch);
        freq[ch - 'a']++;

        // remove characters from queue front while they are repeated
        while (!q.empty() && freq[q.front() - 'a'] > 1){
            q.pop();
        }

        if (q.empty()) {
            // no non-repeating char at this point
            ans += "-1";
            cout << "-1" << " ";
        }
        else {
             // current first non-repeating character
            ans += q.front();
            cout << q.front() << " ";
        }
    }
    cout << endl;
    return ans;
}

int main() {
    string str = "aabccxb";

    cout << FirstNonRepeated(str) << endl;
    return 0;
}