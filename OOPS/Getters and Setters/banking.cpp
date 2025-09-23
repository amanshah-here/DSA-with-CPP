#include<iostream>
#include<string>
using namespace std;

class bank {
    string username;
    double balance;
    string password;
public:

    //? setters

    void setUsername(string uVal) {
        username = uVal;
    }

    void setPassword(string pVal) {
        password = pVal;
    }

    void setBalance(double bVal) {
        balance = bVal;
    }

    //? getters

    string getUsername() {
        return username;
    }

    string getPassword() {
        return password;
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    bank b1;
    b1.setUsername("Aman_Shah");
    b1.setPassword("aman@123");
    b1.setBalance(123456.78);

    cout << "Username: " << b1.getUsername() << endl;
    cout << "Password: " << b1.getPassword() << endl;
    cout << "Balance: " << b1.getBalance() << endl;

    return 0;
}