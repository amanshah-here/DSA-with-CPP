#include<iostream>
using namespace std;

int main() {
    int size;
    cout << "enter size: ";
    cin >> size;

    int* arr = new int[size];   //dynamic memory allocation of array
    for (int i = 0;i < size;i++) {
        cout << "Enter " << i + 1 << " Element: ";
        cin >> arr[i];
    }
    for (int i = 0;i < size;i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
