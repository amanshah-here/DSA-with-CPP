#include<iostream>
using namespace std;

int main(){
    
    //implicit
    cout << (10 / 3) << endl;
    cout << (10 / 3.0) << endl;
    cout << 'A' + 1 << endl;
    cout << 23.5 + 2 + 'A' << endl;

    //explicit
    float pi = 3.14;
    cout <<"\n"<< ((float)10 / 7) << endl;
    cout << (int)pi << endl;
    cout << (char)('A' + 2) << endl;
    cout << (bool)(3 + 2) << endl;
    cout << (bool)3 + 2 << endl;

    return 0;
}