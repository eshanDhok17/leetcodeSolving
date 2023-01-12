class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = size(nums), ans = 0;
        unordered_set<int> mp;
        for(int &num : nums) mp.insert(num);
        for(int i=0; i<n; i++) {
            if(mp.count(nums[i]-1) == 0) {
                int cntr=1;
                int cur = nums[i];
                while(mp.count(cur+1) != 0) {
                    mp.erase(cur);
                    cur++;
                    cntr++;
                }
                ans = max(ans, cntr);
            }
        }
        return ans;
    }
};