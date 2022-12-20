class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> mp;
        for(int &i : nums) mp.insert(i);
        for(int i=1; i<=nums.size(); i++) {
            if(mp.find(i) == mp.end()) res.push_back(i);
        }
        return res;
    }
};