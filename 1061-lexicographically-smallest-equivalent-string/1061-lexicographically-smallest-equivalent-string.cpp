class Solution {
public:
    int par[26];
    void _union(int u, int v) {
        u = _find(u), v = _find(v);
        par[max(u, v)] = min(u, v);
    }
    int _find(int node) {
        if(node == par[node]) return node;
        return par[node] = _find(par[node]);
    }
    string smallestEquivalentString(string s, string t, string b) {
        iota(par, par+26, 0);
        for(int i=0; i<size(s); i++)
            _union(s[i] - 'a', t[i] - 'a');
        
        for(int i=0; i<size(b); i++)
            b[i] = _find(b[i] - 'a') + 'a';
        
        return b;
    }
};