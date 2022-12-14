class Solution {
public:
    void dfs(int row, int col, int &color, int &val, vector<vector<bool>> &vis, vector<vector<int>> &img, vector<vector<int>> &res) {
        int n = size(img), m = size(img[0]);
        vis[row][col] = true;
        res[row][col] = color;
        for(int i=-1; i<=1; i++)
        {
            for(int j=-1; j<=1; j++)
            {
                if(abs(i) == abs(j)) continue;
                else
                {
                    int nr = row+i, nc = col+j;
                    if(nr>=0 and nc>=0 and nr<n and nc<m and img[nr][nc] == val and !vis[nr][nc])
                    {
                        dfs(nr, nc, color, val, vis,img, res);
                    }
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int val = img[sr][sc];
        int n = size(img), m = size(img[0]);
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        vector<vector<int>> res = img;
        dfs(sr, sc, color, val, vis, img, res);
        return res;
    }
};