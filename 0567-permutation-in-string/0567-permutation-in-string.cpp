class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int, int> mp1, mp2;
        for(char&ch : s1) mp1[ch]++;
        int cnt = mp1.size();
        for(int i=0, j=0; j<size(s2); j++) {
            if(mp1.find(s2[j]) != mp1.end()) {
                mp1[s2[j]]--;
                if(mp1[s2[j]] == 0) cnt--;
            }
            // cout << "cntr: " << cnt << endl;
            // cout << j << ' ' << i << endl;
            while(cnt == 0) {
                if(mp1.find(s2[i]) != mp1.end()) {
                    if(mp1[s2[i]] == 0) cnt++;
                    mp1[s2[i]]++;
                }
                if(s1.size() == j-i+1) {
                    return true;
                }
                i++;
            }
        }
        return false;
    }
};