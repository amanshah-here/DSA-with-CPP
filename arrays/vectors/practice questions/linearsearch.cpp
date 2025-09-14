#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> &vec,int target){
    bool isfound = false;
    for(int val:vec){
        if(val==target){
            isfound = true;
        }
    }
    if(isfound==true){
        cout << target << " is found" << endl;
    }else{
        cout << target << " isn't found" << endl;
    }
    return 0;
}

int main()
{
    vector<int> val = {1, 22, 34, 45, 25, 23, 21, 7};
    int target;
    cout << "enter the no to be found:";
    cin >> target;

    search(val, target);
    return 0;
}