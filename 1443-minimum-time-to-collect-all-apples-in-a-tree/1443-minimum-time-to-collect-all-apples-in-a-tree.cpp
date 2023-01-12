class Solution {
private:
    int f(int &node, vector<bool> &vis, vector<vector<int>> &adj, vector<bool> &hasApple) {
        vis[node] = true;
        int apples = 0;
        for(int &it : adj[node]) {
            if(!vis[it]) {
                apples += f(it, vis, adj, hasApple);
            }
        }
        if(node == 0) return apples; // parent node
        if(hasApple[node] or apples > 0) apples += 2;
        return apples;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int ans = 0;
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int node = 0;
        return f(node, vis, adj, hasApple);
    }
};