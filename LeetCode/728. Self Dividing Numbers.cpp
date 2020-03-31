class Solution {
public:
    bool check(int num)
    {
        int temp = num;
        while(temp)
        {
            int div = temp%10;
            temp /= 10;
            if(div == 0 || num%div != 0)
            {
                return false;
            }
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int num = left; num <= right; num++)
        {
            if(check(num))
            {
                res.push_back(num);
            }
        }
        return res;
    }
};