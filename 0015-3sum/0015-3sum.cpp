class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(begin(nums), end(nums));
        for(int i=0; i<size(nums); i++) {
            if(nums[i] > 0) break;
            if(i > 0 and nums[i-1] == nums[i]) continue;
            int s = i+1, e = size(nums)-1;
            
            while(s < e) {
                int newSum = nums[i] + nums[s] + nums[e];
                if(newSum == 0) {
                    res.push_back({nums[i], nums[s], nums[e]});
                    int prev = nums[s], last = nums[e];
                    while(s < e and prev == nums[s]) s++;
                    while(s < e and last == nums[e]) e--;
                }
                else if(newSum < 0) s++;
                else e--;
            }
        }
        
        return res;
    }
};