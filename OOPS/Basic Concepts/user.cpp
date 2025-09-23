#include<iostream>
#include<string>
using namespace std;

class User {
    int id;
    string username;
    string password;
    string bio;

    void deactivate() {
        cout << "Account Deactivated !!" << endl;
    }
    void editBio(string newBio) {
        bio = newBio;
    }
};

int main() {
    User u1;

    cout << sizeof(u1) << endl;
}