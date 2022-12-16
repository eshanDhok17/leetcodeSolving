//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void topoSort(int node, bool vis[], vector<pair<int, int>> adj[], stack<int> &st) {
        vis[node] = true;
        for(auto &it : adj[node]) {
            int v = it.first;
            if(!vis[v]) {
                topoSort(v, vis, adj, st);
            }
        }
        st.push(node);
        return ;
        
    }
    vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<pair<int, int>> adj[n];
        for(int i=0; i<m; i++) {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        stack<int> st;
        bool vis[n] = {false};
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                topoSort(i, vis, adj, st);
            }
        }
        
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        while(!st.empty()) {
            int node = st.top(); st.pop();
            for(auto &it : adj[node]) {
                int v = it.first;
                if(dist[node] + it.second < dist[v]) {
                    dist[v] = dist[node] + it.second;
                }
            }
        }
        for(int i=0; i<n; i++) {
            if(dist[i] == 1e9) {
                dist[i] = -1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends