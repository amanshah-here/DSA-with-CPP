#include<iostream> 
#include<unordered_map> 
#include<string> 
using namespace std; 

int main() {
    unordered_map<string, int> m; // map: country -> population

    // Inserting some (country: population)
    m["India"] = 150;
    m["England"] = 56; 
    m["China"] = 150; 
    m["US"] = 60; 

    m.erase("US"); // remove key "US"

    for (auto& pair : m) { // iterate and print key-value pairs
        cout << "(" << pair.first << ", " << pair.second << ") " << endl;
    }

    if (m.count("England")) { // check if England exists
        cout << "England exists in map and have population: " << m["England"] << endl;
    }
    else {
        cout << "England doesn't exists" << endl; 
    }

    if (m.count("Canada")) { // check if Canada exists
        cout << "Canada exists in map and have population: " << m["Canada"] << endl;
    }
    else {
        cout << "Canada doesn't exists" << endl;
    }
    return 0; 
}