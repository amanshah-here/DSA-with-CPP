#include<iostream>
using namespace std;

char increment(char ch){

    if (ch == 'z')
    {
        return 'a';
    }else if(ch == 'Z'){
        return 'A';
    }

    return ch + 1;
}

int main(){
    char ch;
    cout << "enter an alphabet character: ";
    cin >> ch;

    cout << "character after " << ch << " is: " << increment(ch) << endl;

    return 0;
}