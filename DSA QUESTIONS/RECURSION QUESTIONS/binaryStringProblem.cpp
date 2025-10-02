#include<iostream>
#include<string>
using namespace std;

void binaryString(int n, string ans) {
    if (n == 0) {
        cout << ans << ", ";
        return;
    }
        if (ans[ans.length() - 1] != '1') {
        binaryString(n - 1, ans + '0');
        binaryString(n - 1, ans + '1');
    }
    else {
        binaryString(n - 1, ans + '0');
    }
}

int main() {
    int n;
    int lastElement = 0;
    string ans = "";
    cout << "Enter the value of N: ";
    cin >> n;
    binaryString(n, ans);
    return 0;
}