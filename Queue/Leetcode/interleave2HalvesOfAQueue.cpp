#include<iostream>
#include<queue>
using namespace std;

void interLeave(queue<int>& org) {
    // store first half in a temporary queue
    queue<int> first;
    int n = org.size();

    for (int i = 0; i < n / 2; i++) {
        first.push(org.front());
        org.pop();
    }

    // interleave elements from first half and remaining half
    while (!first.empty()) {
        org.push(first.front()); // push from first half
        first.pop();

        org.push(org.front());   // then push next from second half
        org.pop();
    }
}

int main() {
    queue<int> org;

    for (int i = 1; i <= 10; i++) {
        org.push(i);
    }

    interLeave(org);

    while (!org.empty()) {
        cout << org.front() << " ";
        org.pop();
    }

    return 0;
}