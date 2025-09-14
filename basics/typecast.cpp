#include<iostream>
using namespace std;

int main()
{
    //implicit type conversion
    int price = 100;
    double newprice = price;
    cout << "newprice:" << newprice << endl;

    //explicit type casting
    double salary = 20000.35;
    int newsalary = (int)salary;
    cout << "new salary:" << newsalary << endl;
    return 0;
}