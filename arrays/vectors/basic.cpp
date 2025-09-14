#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec;
    vector<char> vec1 = {'a', 'b', 'c', 'd', 'e'};
    vector<double> vec2(3, 2.6);
    cout << vec1[0] << endl;
    cout << vec1[1] << endl;
    cout << vec1[2] << endl;
    cout << vec1[3] << endl;
    cout << vec2[0] << endl;
    cout << vec2[1] << endl;
    return 0;

}