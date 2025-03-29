/***
 * Given an array of positive numbers and a positive number ‘k’,
 * find the maximum sum of any contiguous subarray of size ‘k’.
 * 
 * Input: [2, 1, 5, 1, 3, 2], k=3 
   Output: 9
   Explanation: Subarray with maximum sum is [5, 1, 3].

   Input: [2, 3, 4, 1, 5], k=2 
   Output: 7
   Explanation: Subarray with maximum sum is [3, 4].

   Question: 
   1. Can value of K greater than size of array?
 */

#include<iostream>
#include<vector>

using namespace std;

int maxSumSubarray(vector<int>& nums, int k)
{
    int l = nums.size();
    int temp = 0, ans = 0;
    for(int i=0, j = 0; j < l; j++)
    {
        temp += nums[j];
        if(j >= k-1)
        {
            ans = max(temp, ans);
            temp -= nums[i];
            i++;
        }
    }

    /** 
     * If value of K greater than size of array then
     * it makes no sense to take summation of all elements
     * as there will be no K amount of numbers
    */
    return ans;
}

int main()
{
    vector<int> nums = {2, 1, 5, 1, 3, 2};

    int res = maxSumSubarray(nums, 3);
    cout << res << endl;

    return 0;
}
