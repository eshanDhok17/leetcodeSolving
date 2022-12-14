//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vis[row][col] = true;
        for(int i=-1; i<=1; i++) {
            for(int j=-1; j<=1; j++) {
                int nr = row+i, nc = col+j;
                if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc] == '1' and !vis[nr][nc]) {
                    dfs(nr, nc, vis, grid);
                }
            }
        }
        return ;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1' and vis[i][j] == false) {
                    dfs(i, j, vis, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends