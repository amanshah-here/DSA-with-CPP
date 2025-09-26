#include<iostream>
using namespace std;

int sum(int a,int b){
    return a + b;
}

int sum(int a,int b,int c){
    return a + b + c;
}

double sum(double x,double y){
    return x + y;
}

int main(){
    cout << "sum: " << sum(2, 4) << endl;
    cout << "sum: " << sum(2, 3, 5) << endl;
    cout << "sum: " << sum(1.3, 2.3) << endl;

    return 0;
}