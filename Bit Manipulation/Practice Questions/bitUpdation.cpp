#include<iostream>
using namespace std;

int bit_Updation(int num, int pos, int val) {

    if (val == 0) {
        return num & (~(1 << pos));
    }
    else{
        return num | (1 << pos);
    }
}

int main() {
    int num;
    int pos;
    int val;

    cout << "Enter the Number: ";
    cin >> num;
    cout << "Enter the Position of Bit: ";
    cin >> pos;
    cout << "Enter the Value: ";
    cin >> val;

    cout << "Before Updation Number: " << num << endl;
    cout << "After Updation Number: " << bit_Updation(num, pos, val) << endl;

    return 0;  
}