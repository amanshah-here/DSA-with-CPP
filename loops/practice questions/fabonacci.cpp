#include<iostream>
using namespace std;

int main(){
    int n;
    int first = 0;
    int second = 1;
    cout << "enter a number:";
    cin >> n;

    cout << "FABONACCI SERIES:" << endl;
    if (n >= 1)
        cout << first << " , ";
    if(n >= 2)
        cout << second << " , ";

    for (int i = 2; i <= n;i++){
        int next = first + second;
        cout << next << " , ";
        
        //updation of first and second
        first = second;
        second = next;
    }
    return 0;
}