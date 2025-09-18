#include<iostream>
#include<cstring>
using namespace std;

void reverse(char* str) {
    int len = strlen(str);
    int st = 0;
    int end = len - 1;
    while (st <= end) {
        swap(str[st], str[end]);
        st++, end--;
    }
    cout << str << endl;
}

int main() {
    char str[50];

    cout << "Enter a String : ";
    cin.getline(str, 50);

    reverse(str);

    return 0;
}