class Solution {
public:
    int par[26];
    int find(int node) {
        if(par[node] == node) return node;
        return par[node] = find(par[node]);
    }
    void uni(int v, int u) {
        v = find(v), u = find(u);
        if(v != u) par[max(v, u)] = min(v, u);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        iota(par, par+26, 0);
        int n=size(s1);
        for(int i=0; i<n; i++) {
            uni(s1[i]-'a', s2[i]-'a');
        }
        for(int i=0; i<baseStr.size(); i++) {
            baseStr[i] = find(baseStr[i]-'a') + 'a';
        }
        return baseStr;
    }
};