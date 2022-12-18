class Solution {
private:
    int dp[201][201];
    int solve(int row, int col, vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        if(row == n-1) return grid[row][col];
        if(dp[row][col] != -1) return dp[row][col];
        int mini = 1e9;
        for(int newCol = 0; newCol < m; newCol++) {
            if (newCol == col) continue;
            mini = min(mini, grid[row][col] + solve(row+1, newCol, grid));
        }
        return dp[row][col] = mini;
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        int mini = 1e9;
        for(int i=0; i<m; i++) {
            mini = min(mini, solve(0, i, grid));
        }
        return mini;
    }
};