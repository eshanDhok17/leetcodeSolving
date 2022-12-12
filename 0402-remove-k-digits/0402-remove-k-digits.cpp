class Solution {
public:
    string removeKdigits(string &num, int &k) {
        string res = "";
        stack<char> st;
        for(char &c : num) {
            while(!st.empty() and st.top() > c and k) {
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(k--) st.pop(); // removing extra k digits
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        int j;
        for(j=0; j<res.size(); j++) if(res[j] != '0') break; // removing 
        string ans = res.substr(j, res.size());
        return ans.size() > 0? ans : "0";
    }
};