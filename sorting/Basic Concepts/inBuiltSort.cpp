#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int printArray(vector<int>& arr){
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int inBuiltSort_asc(vector<int>& arr){
    sort(arr.begin(), arr.end());

    printArray(arr);
}

int inBuiltSort_desc(vector<int>& arr){
    sort(arr.begin(), arr.end(), greater<int>());

    printArray(arr);
}

int main(){
    vector<int> arr = {1, 4, 1, 3, 2, 7, 8, 4, 3, 7};

    inBuiltSort_asc(arr);

    inBuiltSort_desc(arr);

    return 0;
}