#include<iostream>
#include<vector>
using namespace std;

int reverse(vector<int>& vec){
    int strt = 0;
    int end = vec.size() - 1;
    while(strt<end){
        swap(vec[strt], vec[end]);
        strt++;
        end--;
    }
    return 0;
}

int main(){
    vector<int> vec = {1, 2, 3, 4, 5, 6};
    reverse(vec);
    for (int val:vec){
        cout << val << " ";
    }
    return 0;
}