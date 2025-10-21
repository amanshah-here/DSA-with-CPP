#include<iostream>
#include<deque>
#include<vector>
using namespace std;

/*
  *Asteroid Collision (annotated)

  *Problem summary:
  - We are given a sequence of integers representing asteroids placed left-to-right.
    Positive value => asteroid moving to the right.
    Negative value => asteroid moving to the left.
  - When two asteroids moving in opposite directions meet, they collide. The one
    with the larger absolute value survives; if both have equal absolute value,
    both are destroyed.

  This implementation (function `Collision`) simulates those interactions and
  returns the list of surviving asteroids (left-to-right).

  *Key idea / invariant:
  - Asteroids only collide when a right-moving asteroid is to the left of a
    left-moving asteroid. So while scanning from left to right, only a newly
    encountered left-moving asteroid can collide with previously seen right-w
    moving asteroids that are still "alive" (tracked at the back of a deque).

  *Complexity:
  - Time: O(n) amortized. Each asteroid is pushed once and popped at most once.
  - Space: O(n) worst-case for the deque when no collisions occur.
*/

// Returns a vector of surviving asteroids in left-to-right order.
vector<int> Collision(vector<int>& asteroids) {
    // Deque keeps the current survivors in-order (left to right).
    deque<int> q;
    vector<int> ans;

    for (int& val : asteroids) {
        // If asteroid is moving right (positive), it cannot collide
        // with asteroids to its left so we append it to the deque.
        if (val > 0) {
            q.push_back(val);
            continue;
        }

        // val is negative (moving left). It may collide with right-moving
        // asteroids that are currently at the back of the deque.
        bool isDestroyed = false; // whether the current (negative) asteroid dies

        // While there is a candidate collision, resolve collisions.
        while (!q.empty() && q.back() > 0) {

            if (q.back() < abs(val)) {
                // The right-moving asteroid is smaller, It explodes. 
                q.pop_back();
                continue;
            }
            else if (q.back() == abs(val)) {
                // Equal size: both destroy each other. Remove the right-moving
                // asteroid and mark the current one as destroyed.
                q.pop_back();
                isDestroyed = true;
                break;
            }
            else {
                // rightMoving > leftMovingAbs: the left-moving asteroid
                // explodes. We don't change the deque (right asteroid survives).
                isDestroyed = true;
                break;
            }
        }

        // If the left-moving asteroid survived all collisions (or there were
        // no right-moving asteroids to collide with), append it to deque.
        if (!isDestroyed) {
            q.push_back(val);
        }
    }

    // Collect survivors from the deque in left-to-right order into the result vector.
    while (!q.empty()) {
        ans.push_back(q.front());
        q.pop_front();
    }

    return ans;
}

int main() {
    // Small example to demonstrate collisions. You can replace this with other
    // test cases or hook this function to input parsing for online judges.
    vector<int> asteroids = { 10, 30, 20, -25, 45, 10, -10, -40, 40 };

    // Compute survivors
    vector<int> ans = Collision(asteroids);

    // Print survivors separated by spaces
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans.at(i) << " ";
    }
    cout << endl;

    return 0;
}