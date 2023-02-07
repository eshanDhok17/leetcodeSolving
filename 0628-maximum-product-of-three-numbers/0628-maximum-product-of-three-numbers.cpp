class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size()-1;
        long sum1 = nums[0]*nums[1]*nums[2];
        long sum2 = nums[n]*nums[n-1]*nums[n-2];
        long sum3 = nums[0]*nums[1]*nums[n];
        return (int)max(sum1, max(sum3,sum2));
    }
};