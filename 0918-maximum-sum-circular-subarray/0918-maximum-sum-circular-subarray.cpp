class Solution {
public:
    
    /* case 2. circular subarray in [0 .. |  n - 1 .. | .. 2 * n - 1]
       i.e. total sum - min subarray sum in [0 .. n - 1]
   */
    int maxSubarraySumCircular(vector<int>& nums) {
        // use kadane's algo to find out max sub array sum (case 1)
        // handle cases like [-3,-2,-3]
        int maxSubArraySum = kadane(nums);
        if (maxSubArraySum < 0) return maxSubArraySum;
        
        // calculate the total sum
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        // in order to use the same kadane function, we flip the sign
        // then, use kadane's algo to find out min sub array sum
        for (auto &x : nums) x *= -1;
        int minSubArraySum = kadane(nums) * -1;
        // compare case 1 & case 2, take the max
        return max(maxSubArraySum, totalSum - minSubArraySum);
    }
    
    int kadane(vector<int>& nums) {
        int local = nums[0], global = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            local = max(nums[i], local + nums[i]);
            global = max(global, local);
        }
        return global;
    }
};