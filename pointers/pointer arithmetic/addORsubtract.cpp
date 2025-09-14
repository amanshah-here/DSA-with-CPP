#include<iostream>
using namespace std;

int main(){
    int arr[] = {1, 2, 3, 4, 5};

    cout << *arr << endl;
    cout << *(arr + 1) << endl; //! adds 1 int(4 bytes)
    cout << *(arr + 2) << endl; //? adds 2 int(8 bytes)
    cout << *(arr + 3) << endl; //todo adds 3 int(12 bytes)
    return 0;
}