class Solution {
public:
    void dfs(int &node, int &end, vector<int> &path, vector<vector<int>> &graph, vector<vector<int>> &res) {
        if(node == end) {
            res.push_back(path);
            return ;
        }
        for(int &it : graph[node]) {
            path.push_back(it);
            dfs(it, end, path, graph, res);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path(1, 0);
        int start = 0, end = size(graph)-1;
        dfs(start, end, path, graph, res);
        return res;
    }
};