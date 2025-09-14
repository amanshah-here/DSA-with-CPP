#include<iostream>
using namespace std;

int main(){
    int marks;
    cout << "enter the marks:\n";  //input
    cin >> marks;
    
    if(marks>=90)
    {
        cout << "grade:A\n";
    }
    else if(marks>=80 && marks<90)
    {
        cout << "grade:B\n";
    }
    else{
        cout << "grade:C\n";
    }
    return 0;
}