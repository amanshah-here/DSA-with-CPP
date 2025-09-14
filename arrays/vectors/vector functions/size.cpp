#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    vector<int> vec1(3, 45);
    cout << "size of 1st vector: " << vec.size() << endl;
    cout << "size of 2nd vector: " << vec1.size() << endl;
    return 0;

}