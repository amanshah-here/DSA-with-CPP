#include<iostream>
using namespace std;

int main(){
    int n;

    cout << "enter a number:";
    cin >> n;

    for (int i = 0; i < n;i++){
        cout << i+1 << " ";
    }
    cout << endl;
    int i = 0;
    while(i<n){

        cout << i + 1 << " ";
        i++;
    }

    return 0;
}