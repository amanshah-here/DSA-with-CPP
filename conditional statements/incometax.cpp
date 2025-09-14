#include<iostream>
using namespace std;

int main(){

    int income;
    float tax;

    cout << "ENTER YOUR INCOME(IN LAKHS): ";
    cin >> income;

    if(income<5){
        cout << "There is no tax to pay....";
    }
    else if(income<=10){
        tax = .2 * income;
        cout << "TAX : " << tax << "Lac" << endl;
    }
    else{
        tax = .3 * income;
        cout << "TAX : " << tax << "Lac " << endl;
    }

    return 0;
}