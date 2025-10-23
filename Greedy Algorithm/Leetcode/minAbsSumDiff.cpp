#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long minSum(vector<int>& A, vector<int>& B) {

    // Sorting both vectors in ascending order to minimize the absolute difference.
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    long long sum = 0;

    //adding the absolute difference to the Sum.
    for (int i = 0; i < A.size(); i++) {
        sum += abs(A[i] - B[i]);
    }

    return sum;
}

int main() {
    vector<int> A = { 1,2,3 };
    vector<int> B = { 2,2,1 };

    cout << "Minimum Absolute Difference Sum: " << minSum(A, B) << endl;;
    return 0;
}