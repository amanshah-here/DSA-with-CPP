#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
    // map from integer key -> string value
    map<int, string> m;

    // insert some key-value pairs (or assign values)

    m[101] = "aman";   // first insert for key 101
    m[110] = "chuha";  // insert key 110
    m[116] = "nitin";  // insert key 116
    m[131] = "aman";   // insert key 131


    // assign to an existing key overwrites its value
    m[101] = "suar";   // key 101 now maps to "suar"

    // count(key) returns 1 if key exists, 0 otherwise
    cout << m.count(101) << endl; // prints 1
    cout << m.count(119) << endl; // prints 0 (119 not present)

    // iterate over map (ordered by key)
    for (auto iter : m) {
        cout << "Key: " << iter.first << " -> Value: " << iter.second << endl;
    }

    return 0;
}