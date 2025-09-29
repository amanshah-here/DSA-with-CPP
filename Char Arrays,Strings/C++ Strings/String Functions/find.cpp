#include<iostream>
#include<string>
using namespace std;

int main() {
    string str = "I love coding in c++ and java. c++ is a good language";

    cout << str.find("c++") << endl;    //? returns the first occurance index of the "c++"" in "str"

    cout << str.find("c++", 20) << endl;    //? returns the first occurance index of the "c++"" in "str" starting from or after index 20

    cout << str.find("python") << endl;     //? returns a number equivalent to -1 if the "python" not found
    
    return 0;
}