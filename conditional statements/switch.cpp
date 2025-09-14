#include<iostream>
using namespace std;

int main(){

    int day;
    cout << "enter day number:";
    cin >> day;

    switch(day){
        case 1:
            cout << "monday\n ";
            break;
        case 2:
            cout << "tuesday\n";
            break;
        case 3:
            cout << "wednesday\n";
            break;
        case 4:
            cout << "thrusday\n";
            break;
        case 5:
            cout << "friday\n";
            break;
        case 6:
            cout << "saturday \n";
            break;
        case 7:
            cout << "sunday\n";
            break;
        default:
            cout << "invalid input\n";
    }

    return 0;
}