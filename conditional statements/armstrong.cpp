#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int num;
    int rem;
    int sum = 0;

    cout << "enter a number:";
    cin >> num;

    int num1 = num;
    int i = 0;
    while(num > 0){
        // cout << "step" << i + 1 << endl;
        rem = num % 10;
        // cout << "rem:" << rem<<endl;
        sum = sum + pow(rem,3);
        // cout<<"power:"<<pow(rem,3)<<endl;
        // cout << "sum:" << sum<<endl;
        num /= 10;
        // cout << "num:" << num<<"\n"<<endl;
        // i++;
    }
    cout << sum<<endl;
    if(sum == num1)
        cout << num1 << " is an armstrong" << endl;
    else
        cout << num1 << " is not an armstrong" << endl;
    
    return 0;

}