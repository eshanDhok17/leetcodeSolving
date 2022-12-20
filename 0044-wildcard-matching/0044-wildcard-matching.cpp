class Solution {
private:
    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if(j < 0 and i < 0) return true;
        if(j < 0 and i >= 0) return false;
        if(i < 0 and j >= 0) {
            for(int t=0; t<=j; t++) if(p[t] != '*') return false;
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j]; //Memoization DP
        
        if(s[i] == p[j] or p[j] == '?') {
            return dp[i][j] = f(i-1, j-1, s, p, dp);
        }
        if(p[j] == '*') {
            return dp[i][j] = f(i, j-1, s, p, dp) | f(i-1, j, s, p, dp);
        }
        else return false;
    }
    
public: 
    bool isMatch(string s, string p) {
        int n = size(s), m = size(p);
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int ans = f(n-1, m-1, s, p, dp);
        dp.clear(); // Explicit space cleared.
        return ans;
    }
};