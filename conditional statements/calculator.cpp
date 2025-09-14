#include<iostream>
using namespace std;

int main(){

    int choice;
    int num1, num2;

    cout << "enter 1st number:";
    cin >> num1;
    cout << "enter 2nd number:";
    cin >> num2;

    cout << "PRESS 1 FOR ADDITION\n";
    cout << "PRESS 2 FOR SUBTRACTION\n";
    cout << "PRESS 3 FOR MULTIPLICATION\n";
    cout << "PRESS 4 FOR DIVISION\n";
    cout << "PRESS 5 FOR MODULATION\n";

    cout << "\nENTER YOUR CHOICE: ";
    cin >> choice;

    switch(choice){
        
        case 1:
            cout << "sum : " << num1 + num2 << endl;
            break;
        case 2:
            cout << "difference : " << num1 - num2 << endl;
            break;
        case 3:
            cout << "product : " << num1 * num2 << endl;
            break;
        case 4:
            cout << "quotient : " << num1 / num2 << endl;
            break;
        case 5:
            cout << "remainder : " << num1 % num2 << endl;
            break;
        default:
            cout << "INVALID INPUT" << endl;
    }
    return 0;
}