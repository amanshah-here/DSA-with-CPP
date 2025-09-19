#include<iostream>
using namespace std;

void funcInt() {
    int* ptr = new int;
    *ptr = 10;

    cout << *ptr << endl;

    delete ptr;
}
void func(int size) {
    int* ptr = new int[size];

    for (int i = 0;i < size; i++) {
        cout << "Enter " << i + 1 << " Element: ";
        cin >> ptr[i];
    }
    for (int i = 0;i < size;i++) {
        cout << ptr[i] << " ";
    }
    cout << endl; 

    delete[] ptr;
}

int main() {
    int size;

    cout << "Enter size: ";
    cin >> size;

    func(size);
    funcInt();

    return 0;
}