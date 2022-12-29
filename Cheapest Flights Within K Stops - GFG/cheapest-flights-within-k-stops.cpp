//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
    Intuition:
        Apply a modified dijkstra's Algorithm which stores the stops and not the distance,
        here as we can see the priority is to be given to the stops since the plain might reach
        the destination in the shortest path but might exceed the stops.
        hence we push into queue according to stops.
        Note: also, we cam use queue data structure instead of priority queue since the stops will
        be monotonically increasing from 0 -> 1 -> 2 and so on so we can reduce the logarithmic
        factor of priority queue which brings the smallest element at the top.
*/

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
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


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends