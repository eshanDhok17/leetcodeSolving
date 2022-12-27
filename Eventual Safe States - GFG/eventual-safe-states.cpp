//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> res;
        vector<int> nadj[V];
        queue<int> q;
        // reverse graph
        for(int i=0; i<V; i++) 
        {
            for(int &it : adj[i])
            {
                nadj[it].push_back(i);
            }
        }
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++)
        {
            for(auto it : nadj[i])
            {
                indegree[it]++;
            }
        }
        for(int i=0; i<V; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front(); q.pop();
            res.push_back(node);
            for(int it : nadj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends