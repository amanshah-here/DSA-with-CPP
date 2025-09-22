#include<iostream>
using namespace std;

int fast(int num, int power) {  // O(log n)
    int ans = 1;

    //CORNER CASES
    if (num == 0) return 0;
    if (power == 0) return 1;
    if (num == 1) return 1;     
    if (power == 1) return num;
    if (num == -1 && power % 2 == 0) return 1;
    if (num == -1 && power % 2 != 0) return -1;

    
        while (power > 0) {
        int lastDigit = power & 1;  //finding the last bit of power.
        if (lastDigit == 1) {
            ans *= num;
            num *= num;
        }
        else {
            num *= num;
        }
        power = power >> 1; // shifting to the next last digit.
    }
    return ans;
}

int main() {
    int num,power;
    cout << "Enter a Number: ";
    cin >> num;
    cout << "Enter Power Of " << num << ": ";
    cin >> power;

    cout << num << " To the Power " << power << ": " << fast(num, power) << endl;

    return 0;
}