class Solution {
public:
    int cntr = 0;
    int dp[101][101];
    int f(int i, int j) {
        cntr += 1;
        if(i < 0 or j < 0) return 0;
        if(i == 0 and j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int left = f(i-1, j);
        int up = f(i, j-1);
        return dp[i][j] = f(i-1, j) + f(i, j-1);
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        int ans = f(m-1, n-1);
        cout << "number of times fxn ran: " << cntr << endl;
        return ans;
    }
};