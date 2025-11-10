#include<iostream>
#include<queue>
using namespace std;

int main() {
    priority_queue<int> pq;

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
        return 0;
}