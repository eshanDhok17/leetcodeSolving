class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp;
        vector<int> v;
        for(auto &ch:p) mp[ch]++;
        int cnt=mp.size(), size=s.size(), i=0, j=0, k=p.size();
        
        while(j<size){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0) cnt--;
            }
            
            if(j-i+1 < k) j++;
            
            else if(j-i+1 == k) {
                if(cnt ==0) v.push_back(i);
                
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1) cnt++;
                }
                
                i++; j++; //slide window
            }
        }
        return v;
    }
};