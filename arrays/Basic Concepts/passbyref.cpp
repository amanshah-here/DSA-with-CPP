#include<iostream>
using namespace std;

int change(int arr[],int size){

    cout << "in function\n";
    for (int i = 0; i < size;i++){
        cout << arr[i] << " ";

        arr[i] *= 2;
    }
}

int main()
{
    int array[] = {1, 2, 3, 4};

    change(array, 4); //! Arrays are always passed by reference
      
    cout << "\nin main\n";
    for (int i = 0; i < 4;i++){
        cout << array[i]<<" ";
    }
        return 0;

}