class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long res = 1e9, sum = 0;
        for(int i=0, j=0; j<size(nums); j++)
        {
            sum += nums[j];
            while(sum >= target)
            {
                res = min(res, (long)(j-i+1));
                sum -= nums[i];
                i++;
            }
        }
        return res == 1e9? 0 : (int)res;
    }
};