class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> output;
        output.push_back(pairs[0]);
        for(int i=1; i<pairs.size(); i++) {
            if(output.back()[1] >= pairs[i][0]) {
                output.back()[1] = min(output.back()[1] , pairs[i][1]);
            }
            else output.push_back(pairs[i]); 
        }
        return output.size();
    }
};