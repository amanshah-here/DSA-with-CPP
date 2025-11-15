#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
    map<string, int> m; // map from country name to population

    // Insert some country -> population entries 
    m["India"] = 150;
    m["England"] = 56;
    m["China"] = 150;
    m["US"] = 60;
    m["UK"] = 50;
    m["UAE"] = 97;

    m.erase("US"); // remove the entry with key "US"

    // Iterate over map (ordered by key) and print each pair
    for (auto& pair : m) {
        cout << "(" << pair.first << ", " << pair.second << ") " << endl;
    }

    // Check for a key using count() which returns 1 if present
    if (m.count("England")) {
        cout << "England exists in map and have population: " << m["England"] << endl;
    }
    else {
        cout << "England doesn't exists" << endl;
    }

    // Demonstrate a negative lookup for a key that was not inserted
    if (m.count("Canada")) {
        cout << "Canada exists in map and have population: " << m["Canada"] << endl;
    }
    else {
        cout << "Canada doesn't exists" << endl;
    }

    return 0; 
}