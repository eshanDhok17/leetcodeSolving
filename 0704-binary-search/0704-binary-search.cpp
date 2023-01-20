class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0, m, j=nums.size()-1; i<=j; ) {
            m = i + (j-i)/2;
            if(nums[m] == target) return m;
            if(nums[m] > target) j = m-1;
            else i = m+1;
        }
        return -1;
    }
};