#include<iostream>
using namespace std;

int main(){
    int first = 0;
    int sec = 1;
    int third;
    int n;

    cout << "enter the value of n:" << endl;
    cin >> n;

    for (int i = 2; i <= n;i++){
        third = first + sec;
        first = sec;
        sec = third;
    }
    cout << n << "th  FIBONACCI TERM : " << sec << endl;

    return 0;
}