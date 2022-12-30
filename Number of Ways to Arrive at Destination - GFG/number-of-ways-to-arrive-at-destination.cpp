//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

typedef pair<int, int> pi;
class Solution {
  public:
    int countPaths(int &n, vector<vector<int>>& roads) {
        // code here
        int mod = 1e9+7;
        vector<pi> adj[n];
        for(int i=0; i<roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        vector<int> dist(n, 1e9), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int node = top.first;
            int distWt = top.second;
            for(auto &it : adj[node]) {
                int adjNode = it.first, wt = it.second;
                if(wt + distWt < dist[adjNode]) {
                    dist[adjNode] = wt + distWt;
                    pq.push({adjNode, dist[adjNode]});
                    ways[adjNode] = ways[node];
                }
                else if(wt + distWt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends