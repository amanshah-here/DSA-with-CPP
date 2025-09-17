#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec;

    vec.push_back(10);              // vectors work by creating a new memory double in the size of current memory
    vec.push_back(20);              // and transfers the data in the current memory to the new memory
    vec.push_back(23);              // and the deletes the old memory                  

    cout << "size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;

    return 0;

}