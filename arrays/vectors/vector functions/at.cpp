#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec;
   
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(23);

        cout << vec.at(0) << endl;
        cout << vec.at(2) << endl;

        return 0;

}