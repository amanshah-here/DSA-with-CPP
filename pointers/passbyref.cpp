#include<iostream>
using namespace std;

//through pointer
void changeA(int *ptr){
    *ptr = 20;
}

//through alias
void changeB(int &b){
    b = 20;
}

int main(){
    int A = 10;
    int B = 10;

    changeA(&A);
    changeB(B);
    
    cout << "new a:" << A << endl;
    cout << "new b:" << B << endl;
    return 0;
}