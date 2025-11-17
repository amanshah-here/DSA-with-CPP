#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

// Check if two strings are anagrams using hash map
bool isAnagram(string s1, string s2) {
    // Anagrams must have the same length
    if (s1.size() != s2.size()) return false;

    unordered_map<char, int> m;

    // Count frequency of each character in s1
    for (char c : s1) {
        if (m.count(c)) m[c]++;
        else m[c] = 1;
    }

    // Check if s2 has same characters with same frequency
    for (char c : s2) {
        if (!m.count(c)) return false;  // Character not found in s1
        else {
            m[c]--;  // Decrement frequency

            if (m[c] == 0) m.erase(c);
        }
    }

    return true;
}

int main() {
    // Test strings
    string s1 = "race";
    string s2 = "care";

    // Check and display result
    isAnagram(s1, s2) ? cout << "both strings are anagram." : cout << "Strings are not anagram.";

    return 0;
}