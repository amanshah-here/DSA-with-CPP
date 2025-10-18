#include<iostream>
#include<string>
#include<stack>
using namespace std;

string decode(string str) {
    stack<char> s;
    string ans = "";
    for (char ch : str) {
        if (ch != ']') {
            s.push(ch);
        }
        else {
            string temp = "";
            while (s.top() != '[') {
                temp.push_back(s.top());
                s.pop();
            }
            s.pop();

            int st = 0, end = temp.size() - 1;

            while (st <= end) {
                swap(temp[st++], temp[end--]);
            }
            char i = s.top();
            s.pop();

            string temp2 = "";
            while (!s.empty()) {
                temp2.push_back(s.top());
                s.pop();
            }

            st = 0, end = temp2.size() - 1;
            while (st <= end) {
                swap(temp2[st++], temp2[end--]);
            }
            ans += temp2;

            while (i != '0') {
                ans += temp;
                i--;
            }
        }
    }
    string temp2 = "";
    while (!s.empty()) {
        temp2.push_back(s.top());
        s.pop();
    }

    int st = 0, end = temp2.size() - 1;
    while (st <= end) {
        swap(temp2[st++], temp2[end--]);
    }
    ans += temp2;

    return ans;
}

int main() {
    string str = "3[a]2[c]";

    cout<<decode(str);
    return 0;
}