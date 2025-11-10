#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;
    priority_queue<string, vector<string>, greater<string>> pq2;

    pq.push(5);
    pq.push(3);
    pq.push(10);
    pq.push(23);
    pq.push(1);
    pq.push(7);

    while (!pq.empty()) {
        cout << "Top: " << pq.top() << endl;
        pq.pop();
    }

    cout << endl;

    pq2.push("Hello World");
    pq2.push("Aman Shah");
    pq2.push("Happy Birthday");
    pq2.push("Stay Positive");
    pq2.push("Be Kind");
    pq2.push("Stay Happy");

    while (!pq2.empty()) {
        cout << "Top: " << pq2.top() << endl;
        pq2.pop();
    }

    return 0;
}