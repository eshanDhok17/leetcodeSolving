class Solution {
public:
    int dp[101];
    int f(int i, vector<int> &nums) {
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(f(i-1, nums), f(i-2, nums) + nums[i]);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return f(nums.size()-1, nums);
    }
};