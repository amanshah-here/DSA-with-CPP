#include<iostream>
#include<string>
#include<queue>
using namespace std;

// comparator functor to create a max-heap by pair.second
struct Compare {
    bool operator () (pair<string, int>& p1, pair<string, int>& p2) {
        return p1.second < p2.second; // greater second -> higher priority
    }
};
int main() {
    // priority queue of (name, Age) with custom comparator
    priority_queue <pair<string, int>, vector<pair<string, int>>, Compare> pq;

    // push some name-score pairs
    pq.push(make_pair("Aman", 20));
    pq.push(make_pair("Nitin", 27));
    pq.push(make_pair("Kishan", 22));
    pq.push(make_pair("Shristi", 19));

    // pop and print until empty
    while (!pq.empty()) {
        cout << "Top: " << pq.top().first << ", " << pq.top().second << endl;
        pq.pop();
    }
}