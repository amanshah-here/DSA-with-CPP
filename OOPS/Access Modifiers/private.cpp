#include<iostream>
#include<string>
using namespace std;

class demo {
    //TODO: By default a class is always private.

private:
    int balance = 23000;
    string username = "Aman_working";
    string password = "aman@123";
};

int main() {
    demo d;
    cout << "Size of object: " << sizeof(d) << endl;

    /*
    This will give an error bcz 'balance','username','password' are private and cannot be accessed outside the class
    cout << d.balance;
    cout << d.username;
    cout << d.password;
    */

    return 0;
}


