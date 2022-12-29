//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        // code here
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> distance(n, vector<int> (m, 1e9));
        distance[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});
        while(!q.empty())
        {
            auto p = q.front(); q.pop();
            int r = p.second.first, c = p.second.second, dist = p.first;
            if(r == destination.first and c == destination.second)
            {
                return dist;
                
            }
            for(int i=-1; i<=1; i++)
            {
                for(int j=-1; j<=1; j++)
                {
                    if(abs(i) == abs(j)) continue;
                    int nr = r+i, nc = c+j;
                    if(nr>=0 and nc>=0 and nr<n and nc<m and grid[nr][nc] == 1 and distance[nr][nc] > dist + 1)
                    {
                        distance[nr][nc] = dist + 1;
                        q.push({distance[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends