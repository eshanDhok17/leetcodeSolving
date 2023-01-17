class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=size(nums);
        int ans = 0, cnt = 0;
        for(int i=1; i<n; i++) {
            if(nums[i-1] > nums[i] or nums[i-1] == nums[i]) {
                cnt = nums[i-1] - nums[i] + 1;
                ans += cnt;
                // cout << nums[i] << endl;
                // cout << cnt << endl;
                nums[i] += cnt;
            }
        }
        return ans;
    }
};