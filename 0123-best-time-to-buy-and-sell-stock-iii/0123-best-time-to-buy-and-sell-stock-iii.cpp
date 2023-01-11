class Solution {
public:
    int dp[100001][2][3];
    /*
            f(index, buy_status, transactions, prices) {
                baseCase -> reach endday
                if(buy and Transact) {
                    either buy or not buy
                }
                else {
                    sell or not sell
                }
                return ans;
            }
    */
    int f(int i, int buy, int cap, vector<int> &prices) {
        if(cap == 0 or i == size(prices)) {
            return 0;
        }
        if(dp[i][buy][cap] != -1) {
            return dp[i][buy][cap];
        }
        int profit = -1e9;
        if(buy) {
            profit = max(f(i+1, 1, cap, prices), -prices[i] + f(i+1, 0, cap, prices));
        }
        else {
            profit = max(f(i+1, 0, cap, prices), +prices[i] + f(i+1, 1, cap-1, prices));
        }
        return dp[i][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = size(prices);
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));
        memset(dp, -1, sizeof(dp));
        // dp[ind][buy][cap];
        //     ind, buy, cap, dp, prices
        return f(0,  1,   2, prices);
    }
};