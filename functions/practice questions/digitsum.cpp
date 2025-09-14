#include<iostream>
using namespace std;

int digitSum(int n){
    int sum=0;
    int rem;
    while(n!=0){
        rem = n % 10;
        sum = sum + rem;
        n = n / 10;
    }
    return sum;
}
int main()
{
    int num;
    cout << "enter the number:";
    cin >> num;

    cout << "sum of digits:" << digitSum(num) << endl;
    
    return 0;
}