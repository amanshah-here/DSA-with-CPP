#include<iostream>
#include<vector>
using namespace std;

//checking the validity of the answer
bool isvalid(vector<int> arr,int students,int books,int maxPages){
    int stu = 1;
    int pages = 0;

    for (int i = 0; i < books;i++){  //O(n)

        if(arr[i]>maxPages)
            return false;

        if(pages+arr[i]<=maxPages){
            pages += arr[i];
        }else{
            stu++;
            pages = arr[i];
        }
    }

    if(stu>students)
        return false;
    else
        return true;
}

int allocation(vector<int>&arr,int students,int books){     //O(logN * n)
    //edge case
    if(students>books)
        return -1;
    
    int ans = -1;
    int sum = 0;
    for (int i = 0; i < arr.size();i++){    //O(n)
        sum += arr[i];
    }

    int st = 0, end = sum;//range of possible answers
    
    //binary search
    while(st<=end){     //O(logN *n)
        int mid = st + (end - st) / 2;

        if(isvalid(arr,students,books,mid)){    //O(n)
            ans = mid;
            end = mid - 1;
        }else{
            st = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {2, 1, 3, 4};
    int students = 2;
    int books = arr.size();

    cout << allocation(arr, students, books);
    return 0;
}