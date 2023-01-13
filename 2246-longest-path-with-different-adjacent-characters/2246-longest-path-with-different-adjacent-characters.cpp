class Solution {
public:
    vector<vector<int>> adj;
    int maxAns = 1, n;
    int dfs(int node, int parNode, string &s) {
        int maxPath = 1;
        for(int &adjNode : adj[node]) {
            if(adjNode != parNode) {
                int path = dfs(adjNode, node, s);
                if(s[node] != s[adjNode]) {
                    maxAns = max(maxAns, maxPath + path);
                    maxPath = max(maxPath, path + 1);
                }
            }
        }
        return maxPath;
    }
    int longestPath(vector<int>& parent, string &s) {
        n = size(parent);
        adj.resize(n);
        for(int i=1; i<n; i++) {
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }
        dfs(0, -1, s);
        return maxAns;
    }
};