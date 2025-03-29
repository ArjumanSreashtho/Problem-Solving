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