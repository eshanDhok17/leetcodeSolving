class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = size(mat), m = size(mat[0]);
        vector<vector<int>> res = mat;
        vector<vector<bool>> vis (n, vector<bool>(m, false));
        queue<pair<int, pair<int, int>>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 0) {
                    q.push({0, {i, j}});
                    vis[i][j] = true;
                }
            }
        }
        while(!q.empty()) {
            auto top = q.front(); q.pop();
            int row = top.second.first, col = top.second.second, dist = top.first;
            res[row][col] = dist;
            for(int i=-1; i<=1; i++) {
                for(int j=-1; j<=1; j++) {
                    if(abs(i) == abs(j)) continue;
                    int nr = row + i, nc = col + j;
                    if(nr >= 0 and nr < n and nc >= 0 and nc < m and !vis[nr][nc]) {
                        q.push({dist+1, {nr, nc}});
                        vis[nr][nc] = true;
                    }
                }
            }
        }
        return res;
    }
};