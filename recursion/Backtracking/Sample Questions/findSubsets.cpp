#include<iostream>
#include<string>
using namespace std;

void subsets(string str, string ans) {
    if (str.size() == 0) {  //base case
        cout << ans << " ";
        return;
    }
    char ch = str[0];

    //Include Choice
    subsets(str.substr(1, str.size() - 1), ans + ch);
    subsets(str.substr(1, str.size() - 1), ans);    //backtrack to the exclude Choice
}

int main() {
    string str;
    string subset = "";
    cout << "Enter a String: ";
    cin >> str;
    subsets(str, subset);
    return 0;
}