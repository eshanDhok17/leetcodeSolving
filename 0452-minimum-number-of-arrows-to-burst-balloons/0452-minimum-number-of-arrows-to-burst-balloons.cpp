class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points), end(points));
        int ans = 0, total = points.size();
        for(int i=1; i<size(points); i++) {
            if(points[i-1][1] >= points[i][0]) {
                points[i][1] = min(points[i][1], points[i-1][1]);
                ans++;
            }
        }
        return total - ans;
    }
};