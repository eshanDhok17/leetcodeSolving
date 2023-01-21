class Solution {
public:
    /*
        i thought i must fill positive elements to right as i encounter them
        which will preserve positive element order and we dont care about zero.
    */
    
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