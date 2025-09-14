#include<iostream>
using namespace std;

int powerof2(int n){

    return (n > 0) && ((n & (n - 1)) == 0);
}
int main()
{
    int n;
    cout << "enter a number:";
    cin >> n;

    if(powerof2(n)){
        cout << "is power of 2\n";
    }
    else{
        cout << "isn't power of 2\n";
    }


    return 0;

}