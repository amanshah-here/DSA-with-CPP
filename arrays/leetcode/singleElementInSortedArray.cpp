#include<iostream>
#include<vector>
using namespace std;

int single(vector<int> &nums){

    int st = 0;
    int end = nums.size() - 1;

    //corner case
    if(nums.size()==1)
        return nums[0];

    while(st<=end){
        int mid = st + (end - st) / 2;
        
        //corner case 2
        if (mid == 0 && nums[mid] != nums[1])
            return nums[mid];

        //corner case 3
        if (mid == nums.size() - 1 && nums[nums.size() - 1] != nums[nums.size() - 2])
            return nums[nums.size() - 1];

            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
                return nums[mid];
        //searching for the single element's position(left or right)
        /*if value at mid is equals to the value of mid-1 that means there is odd no of elements in the left portion and since there
        is only one single element in the array that means the single element is in the left portion*/

        //here we check first if the number of element on either side is odd or even

        //if the number of elements is even
            if (mid % 2 == 0){
                if(nums[mid-1] == nums[mid]){
                    end = mid - 1;
                }else{
                    st = mid + 1;
                }
            }

            //if the number of element is odd
            else{
                if (nums[mid - 1] == nums[mid]){
                    st = mid +1;
                }else{
                    end = mid - 1;
                }
            }

    }
    return -1;
}

int main(){

    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 4, 5,5, 6, 6, 7, 7,9};

    cout << single(nums);
    return 0;
}