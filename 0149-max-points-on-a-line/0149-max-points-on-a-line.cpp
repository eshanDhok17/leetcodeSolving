class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = size(points);
        if(n <= 0) return 0;
        if(n <= 2) return n;
        int maxi = -1;
        for(int i=0; i<n; i++){
            map<double, int> mp;
            int ans = 2;
            for(int j=i+1; j<n; j++) {
                double num = points[j][1] - points[i][1],
                denom = points[j][0] - points[i][0],
                x = INT_MAX;
                if(denom != 0) x = (double)(num/denom);
                mp[x]++;
            }
            for(auto &it : mp) {
                ans = max(ans, it.second+1);
            }
            maxi = max(maxi, ans);
        }
        return maxi;
    }
};