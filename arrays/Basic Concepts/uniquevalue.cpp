#include <iostream>
using namespace std;

int unique(int arr[],int sz){
     for (int i = 0; i < sz; i++) {
        bool isUnique = true;

        // Check if arr[i] appears anywhere else
        for (int j = 0; j < sz; j++) {
            if (i != j && arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }

        if (isUnique==true) {
            cout << arr[i] << " ";
        }
    }
}
int main() {
    int arr[]={1,2,3,4,5,1,2,3,4,5,7,23};
    int sz = 12;
    cout << "Unique elements are: ";
    unique(arr, sz);

    return 0;
}