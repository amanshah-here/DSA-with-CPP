#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec;
        //inputs
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(23);

        vec.pop_back();
        vec.pop_back();

        for(int val:vec){
            cout << val << endl;
        }

        return 0;

}