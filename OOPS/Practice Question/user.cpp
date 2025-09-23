#include<iostream>
#include<string>
using namespace std;

class User {
    int id;
    string password;
public:
    string username;

    //constructor
    User(int id) {
        this->id = id;
    }

    //setter
    void setPassword(string password) {
        this->password = password;
    }

    //getter
    string getPassword() {
        return password;
    }
};

int main() {
    User u1(101);
    u1.username = "aman.ftw";

    u1.setPassword("aman@123");
    cout << "Username: " << u1.username << endl;
    cout << "Password: " << u1.getPassword() << endl;
    return 0;
}