class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        for(int &i : tasks) {
            mp[i]++;
        }
        int ans = 0;
        for(auto &it : mp) {
            int b = it.second;
            if(b == 1) return -1;
            if(b % 3 == 0) {
                ans += b/3;
            }
            else {
            // 
                ans += (b/3) + 1;
            }
        }
        return ans;
    }
};