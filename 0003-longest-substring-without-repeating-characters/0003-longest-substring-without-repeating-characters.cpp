class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int ans = 1;
        unordered_map<char, int> mp;
        for(int i=0, j=0; j<size(s); j++) {
            mp[s[j]]++;
            if(j-i+1 == mp.size()) {
                ans = max(ans, j-i+1);
            }
            while(j-i+1 > mp.size()) {
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};