//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet {
public:
    vector<int> rank, parent;
	DisjointSet(int n) {
		rank.resize(n + 1, 0);
		parent.resize(n + 1);
		for(int i = 0; i <= n; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
	}
	int findPar(int node) {
		if(node == parent[node]) {
			return node;
		}
		return parent[node] = findPar(parent[node]);
	}
	void unionByRank(int u, int v) {
		int ulp_u = findPar(u),
		    ulp_v = findPar(v);
		if(ulp_u == ulp_v) return ;
		if(rank[ulp_u] < rank[ulp_v]) {
			parent[ulp_u] = ulp_v;
		}
		else if (rank[ulp_u] > rank[ulp_v]) {
			parent[ulp_v] = ulp_u;
		}
		else {
			parent[ulp_u] = ulp_v;
			rank[ulp_v]++;
		}
	}
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int cnt = 0;
        for(auto &it : edge) {
            int u = it[0], v = it[1];
            if(ds.findPar(u) == ds.findPar(v)) {
                cnt++;
            }
            else ds.unionByRank(u, v);
        }
        int cntC = 0;
        for(int i=0; i<n; i++) {
            if(ds.parent[i] == i) cntC++;
        }
        if(cnt >= cntC-1) {
            return cntC-1;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends