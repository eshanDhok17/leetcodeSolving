class Solution {
public:
    // backtrack
    void f(int i, int prev, int &lim, vector<int> &nums, vector<int> &ds, vector<vector<int>> &res, set<vector<int>> &st) {
        if(ds.size() > 1) {
            if(!st.count(ds)) {
                st.insert(ds);
                res.push_back(ds);
            }
        }
        for(int ind = i; ind < lim; ind++) {
            if(prev <= nums[ind]) {
                int temp = prev;
                prev = nums[ind];
                ds.push_back(nums[ind]);
                f(ind+1, prev, lim, nums, ds, res, st);
                prev = temp;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<int> ds;
    vector<vector<int>> res;
    set<vector<int>> st;
        int n = size(nums), prev = -1e9;
        f(0, prev, n, nums, ds, res, st);
        return res;
    }
};