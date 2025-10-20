#include<iostream>
#include<deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_back(3);
    dq.push_back(4);

    dq.push_front(2);
    dq.push_front(1);

    dq.pop_front();

    dq.pop_back();

    cout << dq.front() << endl;
    cout << dq.back() << endl;

    return 0;
}