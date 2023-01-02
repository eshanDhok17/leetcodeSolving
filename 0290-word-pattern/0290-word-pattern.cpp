class Solution {
public:
    bool wordPattern(string pat, string s) {
        vector<int> patMap(26, 0);
        unordered_map<string, int> strMap;
        int i = 0, n = pat.size();
        istringstream ss(s);
        for(string token; ss >> token; ++i) {
            if(i == n || patMap[pat[i] - 'a'] != strMap[token])
                return false;
            patMap[pat[i] - 'a'] = strMap[token] = i+1;
            //i+1 because map assigns 0 as default value for key not found
        }
        return i == n;
        
    }
};