class Solution {
    vector<vector<int>> res;
    void f(int ind, vector<int> &nums) {
        if(ind == size(nums)-1) {
            res.push_back(nums);
            return ;
        }
        for(int i=ind; i<size(nums); i++) {
            swap(nums[i], nums[ind]);
            f(ind+1, nums);
            swap(nums[ind], nums[i]);
        }
        return ;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        f(0, nums);
        return res;
    }
};