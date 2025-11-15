#include<iostream>
#include<set>     
#include<string>   
using namespace std;

int main() {
    set<string> s; // ordered set of unique strings

    // Insert country names into the set
    s.insert("India");
    s.insert("China");
    s.insert("England");
    s.insert("USA");
    s.insert("UK");
    s.insert("India"); // duplicate, will be ignored by set
    s.insert("China"); // duplicate, will be ignored by set

    cout << "Size: " << s.size() << endl; // print number of unique elements

    // Iterate and print all elements (in sorted order)
    for (auto& str : s) {
        cout << str << " -> ";
    }
    cout << endl;

    s.erase("England"); // remove an element by value

    // Check for existence after erase
    if (s.find("England") != s.end()) {
        cout << "England Exists." << endl;
    }
    else {
        cout << "England doesn't exists." << endl;
    }

    return 0;
}