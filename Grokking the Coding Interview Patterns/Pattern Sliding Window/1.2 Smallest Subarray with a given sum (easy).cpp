/**
 * Given an array of positive numbers and a positive number ‘S’,
 * find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’.
 * Return 0, if no such subarray exists.
 * 
 * Input: [2, 1, 5, 2, 3, 2], S=7 
   Output: 2
   Explanation: The smallest subarray with a sum great than or equal to '7' is [5, 2].

   Input: [2, 1, 5, 2, 8], S=7 
   Output: 1
   Explanation: The smallest subarray with a sum greater than or equal to '7' is [8].

   Input: [1,1,1,1,1,1,1,1], S=11
   Output: 0
   Explanation: Sum of whole array is less than '11'
 */

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums)
{
    int ans = INT_MAX, temp = 0;
    int l = nums.size();
    for(int i = 0, j = 0; j < l; j++)
    {
        temp += nums[j];

        while(temp >= target)
        {
            ans = min(ans, j-i+1);
            temp -= nums[i++];
        }
    }

    return ans == INT_MAX ? 0 : ans;
}

int main()
{
    vector<int> nums = {2, 1, 5, 2, 3, 2};
    int S = 7;

    int ans = minSubArrayLen(S,nums);

    cout << ans << endl;

    return 0;
}