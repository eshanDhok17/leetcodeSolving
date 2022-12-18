typedef long long ll;
class Solution {
public:
    ll bfs(int &node, vector<ll> &vis, vector<ll> adj[]) {
        vis[node] = 1;
        int cnt = 0;
        queue<ll> q;
        q.push(node);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
            cnt++;
        }
        return cnt;
    }
    ll countPairs(int n, vector<vector<int>>& edges) {
        vector<ll> adj[n], vis(n, 0);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        ll res = 0, total = n;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                int nodes = bfs(i, vis, adj);
                ll unreachable = nodes * (total - nodes);
                if(unreachable > 0) {
                    res += unreachable;
                }
                total -= nodes;
            }
        }
        return res;
    }
};