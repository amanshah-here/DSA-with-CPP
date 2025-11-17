#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
using namespace std;

vector<string> itinerary(unordered_map < string, string>& m) {
    // collect all destinations in a set for quick lookup
    unordered_set<string> s;

    for (auto& pair : m) {
        // each map value is a destination
        s.insert(pair.second);
    }

    // find the starting airport (it never appears as a destination)
    string start;
    for (auto& pair : m) {
        if (s.find(pair.first) == s.end()) {
            // found the start
            start = pair.first;
            break;
        }
    }

    // build the itinerary starting from 'start'
    vector<string> ans;
    ans.push_back(start); // add starting airport

    // follow the mapping until no next flight exists
    while (m.count(start)) {
        ans.push_back(m[start]);      // append next destination
        start = m[start];             // move to next source
    }

    return ans; // return reconstructed path
}

int main() {
    unordered_map<string, string> m;
    // sample tickets: source -> destination
    m["Chennai"] = "Bengaluru";
    m["Mumbai"] = "Delhi";
    m["Goa"] = "Chennai";
    m["Delhi"] = "Goa";

    // compute itinerary from the tickets
    vector<string> ans = itinerary(m);

    // print the itinerary in order
    for (string str : ans) {
        cout << str << " -> ";
    }

    return 0; // exit
}