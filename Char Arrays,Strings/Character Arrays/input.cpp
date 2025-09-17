#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    char msg[50];

    cout << "enter your message: ";
    cin.getline(msg, 50, '.');

    cout << "your message: " << msg << endl;
    return 0;
}