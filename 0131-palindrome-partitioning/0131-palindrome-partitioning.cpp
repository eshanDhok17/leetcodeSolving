class Solution {
    vector<vector<string>> res;
    vector<string> ds;
    void btrk(int ind, string &s) {
        if(ind == size(s)) {
            res.push_back(ds);
            return ;
        }
        for(int i=ind; i<size(s); i++) {
            if(isPali(s, ind, i)) {
                ds.push_back(s.substr(ind, i-ind+1));
                btrk(i+1, s);
                ds.pop_back();
            }
        }
    }
    bool isPali(string &s, int i, int j) {
        while(i<=j) {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string &s) {
        btrk(0, s);
        return res;
    }
};