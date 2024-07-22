class Solution {
public:
    int maxProfit(vector<int>& p) {
        int res=0, lsf=p[0];
        for(int i=0; i<size(p); i++) {
            lsf=min(lsf,p[i]);
            res=max(res,p[i]-lsf);
        }
        return res;
    }
};