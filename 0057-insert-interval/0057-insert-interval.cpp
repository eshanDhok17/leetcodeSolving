class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ni) {
        vector<vector<int>> res;
        in.push_back(ni);
        sort(in.begin(), in.end());
        res.push_back(in[0]);
        int n = in.size(), j=0, i;
        for(i=1; i<n; i++) {
            if(res[j][1] >= in[i][0]) {
                res[j][1] = max(res[j][1], in[i][1]);
            }
            else {
                res.push_back(in[i]);
                j++;
            }
        }
        return res;
    }
};