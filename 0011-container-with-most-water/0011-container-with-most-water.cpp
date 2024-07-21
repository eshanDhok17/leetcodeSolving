class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0, j=size(heights)-1;
        int ans = 0, area = 0;
        while(i < j) {
            area = min(heights[i], heights[j]) * (j - i);
            if(ans < area) ans = area;
            if(heights[i] < heights[j]) {
                i++;
            } else if(heights[i] > heights[j]) {
                j--;
            } else i++, j--;
        }
        return ans;
    }
};