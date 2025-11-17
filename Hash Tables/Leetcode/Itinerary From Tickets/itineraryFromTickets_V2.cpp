#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
using namespace std;

// Find valid itinerary from given tickets using graph traversal
vector<string> itinerary(vector<vector<string>>& tickets) {
    unordered_set<string> s; // Set of all destinations
    unordered_map<string, string> m; // Map source to destination

    for (auto& ticket : tickets) {
        s.insert(ticket[1]); // Add destination to set
        m[ticket[0]] = ticket[1]; // Create mapping from source to destination
    }

    // Find starting city (source that is not a destination)
    string start;
    for (auto& ticket : tickets) {
        if (s.find(ticket[0]) == s.end()) {
            start = ticket[0];
            break;
        }
    }

    // Build the itinerary path by following the mappings
    vector<string> ans;
    ans.push_back(start);

    while (m.count(start)) {
        ans.push_back(m[start]); // Add next destination in itinerary
        start = m[start]; // Move to next location
    }

    return ans;
}

int main() {
    // Test case: tickets with cities and destinations
    vector<vector<string>> tickets = { {"Chennai", "Bengaluru"}, {"Mumbai", "Delhi"}, {"Goa", "Chennai"}, {"Delhi", "Goa"} };

    // Get the valid itinerary
    vector<string> ans = itinerary(tickets);

    // Print the journey route
    for (string str : ans) {
        cout << str << " -> ";
    }

    return 0;
}