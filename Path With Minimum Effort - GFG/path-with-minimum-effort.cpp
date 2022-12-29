//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef pair<int, pair<int, int>> pi;
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int r = it.second.first, c = it.second.second, diff = it.first;
            if(r == n-1 and c == m-1) {
                return diff;
            }
            for(int i=-1; i<=1; i++) {
                for(int j=-1; j<=1; j++) {
                    if(abs(i) == abs(j)) continue;
                    int nr = r+i, nc = c+j;
                    if(nr>=0 and nr<n and nc>=0 and nc<m) {
                        int newEffort = max(abs(heights[nr][nc] - heights[r][c]), diff);
                        if(newEffort < dist[nr][nc]) {
                            dist[nr][nc] = newEffort;
                            pq.push({newEffort, {nr, nc}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends