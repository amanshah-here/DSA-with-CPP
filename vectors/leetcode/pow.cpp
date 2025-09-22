#include<iostream>
using namespace std;

double power(long x,int n)
{   
    //corner cases
    if(n==0)
        return 1.0;
    if(n==1)
        return x;
    if(x==0)
        return 0.0;
    if(x==1)
        return 1.0;
    if(x==-1 && n%2==0)
        return 1.0;
    if(x==-1 && n%2!=0)
        return -1.0;

    long binForm = n;
    double ans = 1;

    //if power is negative number is reciprocled
    if(n<0){
        x = 1 / x;
        binForm = -binForm;
    }

    while(binForm>0){
        if(binForm%2==1){
            ans *= x;
        }
        x *= x;
        binForm /= 2;
        
    }
    return ans;
}

int main(){

    long x = 3;
    int n = 2;

    cout << x << " to the power " << n << " : " << power(x, n) << endl;
    return 0;
}