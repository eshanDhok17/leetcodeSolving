class Solution {
public:
    void topoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
        vis[node] = 1;
        for(int adjNode : adj[node]) {
            if(!vis[adjNode]) {
                topoSort(adjNode, vis, st, adj);
            }
        }
        st.push(node);
    }
        // topo sort not guranteed AC because it does not have a definitive order or unique order
        /*
            dry run this example you will understand
            [2,2,3,-1]
            0
            1
        */
        // if(n1 == n2) return n1;
        // stack<int> st;
        // int n = size(edges);
        // vector<int> adj[n];
        // vector<int> vis(n, 0);
        // for(int i=0; i<n; i++) {
        //     if(edges[i] != -1) {
        //         adj[i].push_back(edges[i]);
        //     }
        // }
        // for(int i=0; i<n; i++) {
        //     if(vis[i] == 0) {
        //         topoSort(i, vis, st, adj);
        //     }
        // }
        // vector<int> topo;
        // while(!st.empty()) {
        //     topo.push_back(st.top());
        //     st.pop();
        // }
        // for(int i : topo) cout << i << ' ';
        // cout << endl;
        // int i, cnt = 0;
        // for(i=0; i<size(topo); i++) {
        //     if(topo[i] == n1 or topo[i] == n2) cnt++;
        //     if(cnt == 2) break;
        // }
        // int e = size(topo)-1;
        // // if(i == e and cnt == 2) return topo[e];
        // if(i == e) return topo[e];
        // return topo[i];
        // // return -1;
        
        // dfs solution
        
        void dfs(int node, vector<int>& edges, vector<int>& distance, vector<bool>& visited){
            visited[node] = true;
            int neighbor = edges[node];
            if (neighbor != -1 && visited[neighbor] == false) {
                distance[neighbor] = distance[node] + 1;
                dfs(neighbor, edges, distance, visited);
            }
        }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        int ans = -1;
        int minDist = INT_MAX;
        vector<int> dist1(n, 0), dist2(n, 0);
        vector<bool> visited1(n, false), visited2(n, false);
        dfs(node1, edges, dist1, visited1);
        dfs(node2, edges, dist2, visited2);
        for(int currNode = 0; currNode < n; currNode++){
            if(visited1[currNode] == true && visited2[currNode] == true && minDist > max(dist1[currNode], dist2[currNode])){
                minDist = max(dist1[currNode], dist2[currNode]);
                ans = currNode;
            }
        }
        return ans;
    }
};