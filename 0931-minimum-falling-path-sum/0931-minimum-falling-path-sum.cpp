class Solution {
private:
    int dp[101][101];
    int f(int i, int j, vector<vector<int>> &matrix) {
        int n = size(matrix), m = size(matrix[0]);
        if(j < 0 or j >= m) return 1e9;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int u = matrix[i][j] + f(i-1, j, matrix); 
        int ld = matrix[i][j] + f(i-1, j-1, matrix); 
        int rd = matrix[i][j] + f(i-1, j+1, matrix);
        return dp[i][j] = min(u, min(ld, rd));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(dp, -1, sizeof(dp));
        int maxi = 1e9, n = size(matrix), m = size(matrix[0]);
        for(int i=0; i<m; i++) {
            maxi = min(maxi, f(n-1, i, matrix));
        }
        return maxi;
    }
};