class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> st;
        for(int i=0; i<size(t); i++) {
            if(i != size(t)-1) st[s[i]]++;
            st[t[i]]--;
        }
        for(auto val : st) {
            if(val.second == -1) return val.first;
        }
        return 'a';
    }
};