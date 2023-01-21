class Solution {
public:
    vector<string> result;
    string solution;
    vector<string> restoreIpAddresses(string &s) {
        solve(s, 0, 0);
        return result;
    }
    void solve(string &s, int ind, int parts) {
        if(ind == s.size() and parts == 4) {
            result.push_back(solution);
            return;
        }
        for(int i = ind; i < s.size(); i++) {
            if(parts < 4 and i-ind < 3 and validIP(s, ind, i)) {
                solution.append(s.substr(ind, i-ind+1));
                parts++;
                if(parts < 4) solution.push_back('.');
                solve(s, i+1, parts);
                if(parts < 4) solution.pop_back();
                parts--;
                for(int j = 0; j < i-ind+1; j++) solution.pop_back();
            }
        }
    }
    bool validIP(string &s, int start, int end) {
        string temp = s.substr(start, end-start+1);
        int ip = stoi(temp);
        if(s[start] == '0' and start != end) return false;
        else if(ip >= 0 and ip <= 255) return true;
        return false;
    }
};