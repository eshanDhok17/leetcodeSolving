class Solution {
    public:
    string reverseWords(string &s) {
        for(int i=0, j=0; j<=size(s); j++) {
            if(s[j] == ' ' or j == size(s)) {
                int e = j-1;
                while(i < e) {
                    swap(s[i++], s[e--]);
                }
                i = j+1;
            }
        }
        return s;
    }
};