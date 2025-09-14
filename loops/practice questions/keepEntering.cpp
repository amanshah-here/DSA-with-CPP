#include<iostream>
using namespace std;

int main(){
    int n;
    
    while(true){
        cout << "ENTER A NUMBER: ";
        cin >> n;
        if(n % 10 == 0)
            break;
    }
    cout << "YOU ENTERED A MULTIPLE OF 10" << endl;

    return 0;
}