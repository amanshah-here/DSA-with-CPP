#include<iostream>
using namespace std;

int main()
{
    int age[5];
    string name[5];

    for (int i = 0; i < 5;i++){
        cout << "enter your name:";
        cin >> name[i];

        cout << "enter your age:";
        cin >> age[i];

    }
    for (int i = 0; i < 5;i++){

        cout << "your name is:" << name[i] << endl;
        cout << "your age is:" << age[i] << endl;
    }
        return 0;

}