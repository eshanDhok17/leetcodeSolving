class Solution {
public:
    int get(string &s) {
        int val = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] < '0' or s[i] > '9') return size(s);
            val = max(val, stoi(s));
        }
        return val;
    }
    int maximumValue(vector<string>& strs) {
        int res = 0;
        for(string &str : strs) {
            res = max(res, get(str));
        }
        return res;
    }
};