typedef long long ll;
class Solution {
public:
    ll dividePlayers(vector<int>& s) {
        if(size(s) == 2) return s[0] * s[1];
        sort(begin(s), end(s));
        ll n = size(s), i = 0, j = n - 1, res = 0;
        ll totSum = accumulate(begin(s), end(s), 0LL);
        if((2 * totSum) % n != 0) return -1;
        totSum /= (n/2);
        n /= 2;
        while(i < j) {
            if(s[i] + s[j] == totSum) {
                res += s[i] * s[j];
                n--;
            }
            i++, j--;
        }
        return n == 0? res : -1;
    }
};