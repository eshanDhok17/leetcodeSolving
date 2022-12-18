class Solution {
public:
    int bfs(int &row, int &col, vector<vector<bool>> &vis, vector<vector<int>> &grid) {
        int n = size(grid), m = size(grid[0]);
        int curArea = 0;
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty()) {
            int row = q.front(). first, col = q.front().second;
            q.pop();
            for(int i=-1; i<=1; i++) {
                for(int j=-1; j<=1; j++) {
                    if(abs(i) == abs(j)) continue;
                    int nr = row + i, nc = col + j;
                    if(nr >= 0 and nr < n and nc >= 0 and nc < m and !vis[nr][nc] and grid[nr][nc] == 1) {
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            curArea++;
        }
        return curArea;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = size(grid), m = size(grid[0]);
        int maxArea = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] and grid[i][j] == 1) {
                    vis[i][j] = true;
                    int curArea = bfs(i, j, vis, grid);
                    maxArea = max(maxArea, curArea);
                }
            }
        }
        return maxArea;
    }
};