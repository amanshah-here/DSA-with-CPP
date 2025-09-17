#include<iostream>
using namespace std;

int main(){
    char ch = 'e';
    char ch1 = 'F';

    int position_of_ch = ch - 'a';
    cout << position_of_ch << endl; //index
   
    position_of_ch = ch1 - 'A';
    cout << position_of_ch << endl; //index

    return 0;
}