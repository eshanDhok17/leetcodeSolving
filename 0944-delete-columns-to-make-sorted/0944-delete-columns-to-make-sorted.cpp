class Solution {
public:
    // nothing just std matrix qs given in form of string
    int minDeletionSize(vector<string>& strs) {
        int row = size(strs);
        int col = size(strs[0]);
        int res = 0;
        for(int j=0; j<col; j++) {
            for(int i=0; i<row-1; i++) {
                if(strs[i][j] > strs[i+1][j]) {
                    res += 1;
                    break;
                }
            }
        }
        return res;
    }
};