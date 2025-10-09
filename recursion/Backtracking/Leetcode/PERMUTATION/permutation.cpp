#include<iostream>
#include<string>
using namespace std;
void permutation(string str, string ans) {
    if (str.size() == 0) {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        string nextStr = str.substr(0, i) + str.substr(i + 1, str.size() - i - 1);      //nextStr is the string excluding str[i] that means it is basically the string (before + after) the str[i].
        permutation(nextStr, ans + ch); //ith character choice to add in permuatation
    }
}
int main() {
    string str = "abc";
    string ans = "";
    permutation(str, ans);
    return 0;
}