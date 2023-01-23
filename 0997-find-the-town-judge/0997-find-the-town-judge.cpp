class Solution {
public:
    // topological sort and indegree
    int findJudge(int n, vector<vector<int>>& trust) {
        // Wrong method - fails on TC
        // vector<int> indegree(n+1);
        // for(auto &t : trust) {
        //     indegree[t[1]]++;
        // }
        // for(int i=1; i<indegree.size(); i++) {
        //     if(n >= 2 and indegree[i] == 1) return -1;
        //     if(indegree[i] == n-1) return i;
        // }
        // return -1;
        
        if(trust.empty() and n == 1) return 1;
		vector<int> out(n+1,0), in(n+1,0);
        for(auto &edge : trust) {
            out[edge[0]]++, in[edge[1]]++;
        }
		for(int i = 0; i <= n; i++) {
            if(out[i] == 0 and in[i] == n-1)
                return i;
        }
        return -1;
    }
};