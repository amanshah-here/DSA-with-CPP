#include<iostream>
#include<vector>
using namespace std;

int maxWater(vector<int> &vec){
    int maxWater = 0;
    for (int i = 0; i < vec.size();i++){
        for (int j = i - 1; j < vec.size();j++){
            int width = j - i;
            int height = min(vec[i], vec[j]);
            int area = width * height;
            maxWater = max(maxWater, area);
        }
    }
    return maxWater;
}

int main(){

    vector<int> vec = {1, 8, 6, 3, 5, 4, 8, 3, 7};
    cout << "maximum water in the containers:" << maxWater(vec);
    return 0;
}