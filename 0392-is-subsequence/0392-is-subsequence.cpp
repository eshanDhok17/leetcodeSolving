class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0, n = s.size(), m = t.size();
        for(int i=0; i<m; i++) {
            if(t[i] == s[j]) {
                j++;
            }
        }
        return j == n;
    }
};