#include<iostream>
#include<string>
#include<vector>
using namespace std;

string removeDuplicates(string& str, string& ans, int i, vector<bool>& map) {
    if (i == str.length() - 1) {    //base case
        if (map[str.at(i) - 'a'] == 0) {
            ans += str.at(i);
        }
        return ans;
    }
    int mapIdx = str.at(i) - 'a';   //index of current character in map

    if (map[mapIdx]) {  //if duplicate.
        removeDuplicates(str, ans, i + 1, map);
    }
    else {  //if not duplicate.
        map[mapIdx] = true;
        ans += str.at(i);
        removeDuplicates(str, ans, i + 1, map);
    }
    return ans;
}

int main() {
    string str = "amannnmmaa";
    string ans = "";
    int i = 0;
    vector<bool> map(26, 0);

    cout << "New string after removing duplicates: " << removeDuplicates(str, ans, i, map) << endl;
    return 0;
}