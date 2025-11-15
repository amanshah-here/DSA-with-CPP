#include<unordered_set> 
#include<iostream>     
#include<string>       
using namespace std;    

int main() {
    unordered_set<string> s; // create an unordered set of strings

    // insert elements (duplicates will be ignored)
    s.insert("India");
    s.insert("USA");
    s.insert("china");
    s.insert("UAE");
    s.insert("England");
    s.insert("India");  // duplicate insert — no effect
    s.insert("England"); // duplicate insert — no effect

    cout << "Size: " << s.size() << endl; // print number of unique items

    for (string country : s) { // iterate over set and print each country
        cout << country << " ";
    }
    cout << endl; 

    s.erase("UAE"); // remove an element from the set

    if (s.find("UAE") != s.end()) { // check whether "UAE" exists
        cout << "UAE exists." << endl;
    }
    else {
        cout << "UAE doesn't exists." << endl; 
    }
    
    return 0;
}