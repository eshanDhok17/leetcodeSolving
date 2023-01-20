class Solution {
public:
    /*
        Intuition:
            1. Merge all intervals and keep the merged intervals [i][1] to minimum
               which will assure us that the previous interval is in consideration
               and the merged one is discarded.
               basically we have to discard intervals which can be merged as they cannot
               satisfy the condition.
            2. return the merge interval's size which will be [a,b], [c,d]
               where b < c.
    */
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> merged;
        merged.push_back(pairs[0]);
        for(int i=1, j=0; i<pairs.size(); i++) {
            if(merged[j][1] >= pairs[i][0]) {
                merged[j][1] = min(merged[j][1], pairs[i][1]);
            }
            else {
                merged.push_back(pairs[i]);
                j++;
            }
        }
        return size(merged);
    }
};