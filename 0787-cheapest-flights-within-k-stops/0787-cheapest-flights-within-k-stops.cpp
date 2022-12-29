class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int &src, int &dst, int &K) {
        vector<pair<int, int>> adj[n];
        for(auto &it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n, 1e9);
        dist[src] = 0; // standing here
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}}); // pair of {stops, {src, dist}}
        while(q.size() > 0) {
            auto it = q.front(); q.pop();
            int stops = it.first, src = it.second.first, cost = it.second.second;
            if(stops > K) continue;
            for(auto &it : adj[src]) {
                int adjNode = it.first, wt = it.second;
                if(cost + wt < dist[adjNode] and stops <= K) {
                    dist[adjNode] = cost + wt;
                    q.push({stops+1, {adjNode, dist[adjNode]}});
                }
            }
        }
        
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};