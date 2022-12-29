class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1; // base case
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> distance(n, vector<int> (m, 1e9));
        distance[0][0] = 0; // Standing at source
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        while(!q.empty())
        {
            auto p = q.front(); q.pop();
            int r = p.second.first, c = p.second.second, dist = p.first;
            if(r == n-1 and c == m-1 and grid[r][c] == 0)
            {
                return dist; // destination reached

            }
            for(int i=-1; i<=1; i++)
            {
                for(int j=-1; j<=1; j++)
                {
                    int nr = r+i, nc = c+j;
                    if(nr>=0 and nc>=0 and nr<n and nc<m and grid[nr][nc] == 0 and distance[nr][nc] > dist + 1) // greedy way
                    {
                        distance[nr][nc] = dist + 1;
                        q.push({distance[nr][nc], {nr, nc}}); // relaxation technique and pushing candidate nto queue
                    }
                }
            }
        }
        return -1; // Cannot reach the destination
    }
};