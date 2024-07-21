class Solution {
public:
    string reverseWords(string str) {
        stringstream s(str);
        string word;
        vector<string> temp;
        
        while(s >> word)
            temp.push_back(word);
        
        string ans = "";
        for(int i=size(temp)-1; i>=0; i--) {
            
            ans += temp[i];
            if(i != 0) ans += " ";
        }
        return ans;
    }
};