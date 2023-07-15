153_Find Minimum in Rotated Sorted Array.cpp

  #if 1
#include <iostream>
#include <vector>

using namespace std;
    int findMin(vector<int>& nums) {
           int lo = 0;
        int hi = nums.size()-1;
        int min = nums[0];
        while(lo<=hi)
        {
            if(nums[lo]<nums[hi])
               min = (min>nums[lo])?nums[lo]:min;
            int mid = lo + (hi-lo) /2;
            min = (min>nums[mid])?nums[mid]:min;
            if(nums[lo] <= nums[mid]) // first half is sorted portion min will
            {              
                lo=mid+1; // search in next half               
            }
            else
            {
               hi=mid-1;
            }            
        }       
        return min;   
    }

int main()
{
    vector<int> data{34,67,90,109,110,3,5,8};
    vector<int> data1{6,7,8,9,10,5};
    vector<int> data2{3,4,5,1,2};
    int res;
    res = findMin(data);
    cout<<"Res = "<<res<<endl;
    res = findMin(data1);
    cout<<"Res = "<<res<<endl;
    res = findMin(data2);
    cout<<"Res = "<<res<<endl;
    return 0;
}
#endif
