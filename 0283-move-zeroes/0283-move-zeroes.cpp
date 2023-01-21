class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1) {
            return ;
        }
        int n = size(nums);
        for(int i=0, j=0; j<n and i<n;) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
            i++;
        }
    }
};