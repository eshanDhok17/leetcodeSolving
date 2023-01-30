class Solution {
public:
    // int dp[40] = {-1};
    // memset(dp, -1, sizeof(dp));
    int f(int n, vector<int>&dp) {
        if(n == 0) return 0;
        if(n == 1 or n == 2) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = f(n-1, dp) + f(n-2, dp) + f(n-3, dp);
    }
    int tribonacci(int n) {
        vector<int>dp(n+1, -1);
        return f(n, dp);
    }
};