class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // long long mx = *max_element(begin(nums), end(nums));
        // vector<long long> vis(mx, 0);
        // for(int i=0; i<nums.size(); i++) {
        //     int ind = nums[i]-1;
        //     if(ind >= 0) vis[ind] = true;
        // }
        // int cntr = 1;
        // for(int i=0; i<=mx; i++) {
        //     if(vis[i] == false) return i+1;
        // }
        // return mx;
        unordered_set<int> mp;
        for(int &i : nums) mp.insert(i);
        int i;
        for(i=1; i<=nums.size(); i++) {
            if(mp.find(i) == mp.end()) return i;
        }
        return i;
    }
};