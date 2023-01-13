class Solution {
public:
    int jump(vector<int>& nums) {
        int n = size(nums);
        int jumps = 0;
        int maxReachable = -1;
        int maxCurrentReachableDestination = 0;
        for(int i=0; i<n; i++)
        {
            if(i == n-1) return jumps;
            maxReachable = max(maxReachable, nums[i] + i);
            if(i == maxCurrentReachableDestination)
            {
                jumps += 1;
                maxCurrentReachableDestination = maxReachable;
            }
        }
        return -1;
    }
};