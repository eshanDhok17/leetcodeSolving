class Solution {
public:
    unordered_set<int>vis;
    int f(int node, vector<int> adj[], vector<bool> hasApple) {
        int res = 0;
        vis.insert(node);
        for(int &i : adj[node]) {
            if(!vis.count(i)) {
                res += f(i, adj, hasApple);
            }
        }
        if(node == 0) return res;
        if(hasApple[node] == true or res > 0) res += 2;
        return res;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int ans = 0;
        vector<int> adj[n];
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        return f(0, adj, hasApple);
    }
};