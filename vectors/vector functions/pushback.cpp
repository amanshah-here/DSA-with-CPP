#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec;
   
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(23);

        for(int val:vec){
            cout << val << endl;
        }

        return 0;

}