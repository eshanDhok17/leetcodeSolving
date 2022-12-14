class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = size(nums)-1, ans = 0;
        while(i < j) {
            ans += (nums[j--]) - (nums[i++]);
        }
        return ans;
    }
};