#include<iostream>
using namespace std;

int sum(int n)
{
    int sum = 0;
    for (int i = 1; i <= n;i++){
        sum = sum + i;
    }
    return sum;

} 
int main()
{
    cout << "sum=" << sum(10) << endl;
    cout << "sum=" << sum(15) << endl;
    return 0;
}