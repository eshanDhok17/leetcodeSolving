class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(), in.end());
        vector<vector<int>> res;
        res.push_back(in[0]);
        for(int i=1, j=0; i<in.size(); i++) {
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