#include<iostream>
using namespace std;

int minimum(int a, int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}
int main()
{
    cout << "\n minimum no:" << minimum(10, 20);
    return 0; 
}