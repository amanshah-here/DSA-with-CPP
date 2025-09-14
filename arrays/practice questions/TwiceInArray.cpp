#include<iostream>
#include<vector>
using namespace std;

int twice(vector<int>& arr){
    for (int i = 0; i < arr.size(); i++){
        for (int j = i+1; j < arr.size(); j++){
            if(arr[i] == arr[j]){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    vector<int> arr1 = {1,2,3,4,5,3,4,5};
    
    (twice(arr)) ? cout << "True" : cout << "False";
    cout << endl;

    (twice(arr1)) ? cout << "True" : cout << "False";
    cout << endl;
   
   
    return 0;
}