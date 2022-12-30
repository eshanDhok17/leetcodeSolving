class Solution {
public:
    typedef pair<long long, long long> pi;
    int countPaths(int &n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<pi> adj[n];
        for(long long i=0; i<roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        vector<long long> dist(n, 1e18), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            long long node = top.second, distWt = top.first;
            for(auto &it : adj[node]) {
                int adjNode = it.first, wt = it.second;
                if(1LL*((long long)wt + (long long)distWt) < dist[adjNode]) {
                    dist[adjNode] = 1LL*((long long)wt + (long long)distWt);
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(1LL*((long long)wt + (long long)distWt) == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};