//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution 
{
  public:
  void toposort(int node, int vis[], vector<pair<int, int>> adj[], stack<int> &st)
  {
      vis[node] = 1;
      for(auto it : adj[node])
      {
          int v = it.first;
          if(!vis[v])
          {
              toposort(v, vis, adj, st);
          }
      }
      st.push(node);
      return ;
  }
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges)
     {
        // code here
        vector<pair<int, int>> adj[n];
        for(int i=0; i<m; i++) 
        {
            int u = edges[i][0],
                v = edges[i][1],
                wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        int vis[n] = {0};
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            if(!vis[i]) 
            {
                toposort(i, vis, adj, st);
            }
        }
        vector<int> dis(n, 1e9);
        dis[0] = 0;
        while(!st.empty())
        {
            int node = st.top(); st.pop();
            for(auto it : adj[node]) 
            {
                int wt = it.second, adjNode = it.first;
                if(dis[node] + wt < dis[adjNode]) 
                {
                    dis[adjNode] = wt + dis[node];
                }
            }
        }
        for(int i=0; i<n; i++)if(dis[i]==1e9)dis[i]=-1;
        return dis;
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