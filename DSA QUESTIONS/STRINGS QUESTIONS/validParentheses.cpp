#include<iostream>
#include<string>
using namespace std;

bool isValidParentheses(string str) {
    string temp = "";   //a temperory string that acts as a stack

    for (char ch : str) {
        if (ch == '[' || ch == '{' || ch == '(') {
            temp.push_back(ch); //push the parentheses into the temp string
        }
        else {
            if (temp.empty()) return false;     //return false if nothing is pushed meaning the string str is empty

            char last = temp.back();    //initializing last varible with the last element of temp string
            temp.pop_back();    //retrieving parentheses from the last of temp string

            if (ch == ']' && last != '[' || ch == '}' && last != '{' || ch == ')' && last != '(') {     //checking if the parentheses of str is the same as the parentheses of temp 
                return false;
            }
        }
    }
    return temp.empty();    //its basically true if everything is popped out
}

int main() {
    string str;

    cout << "Enter the Parentheses : ";
    getline(cin, str);

    (isValidParentheses(str)) ? cout << "True" : cout << "False";

    return 0;
}