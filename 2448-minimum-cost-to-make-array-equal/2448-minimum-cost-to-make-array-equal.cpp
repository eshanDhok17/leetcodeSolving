typedef long long ll;
class Solution {
public:
    ll minCost(vector<int>& nums, vector<int>& cost) {
        ll n = size(nums), res = 0, sum = 0, tot = 0;
    // to find median or central element which
    // will give least operations for all elements
        vector<vector<ll>> vec;
        for(ll i=0; i<n; i++) {
            vec.push_back({nums[i], cost[i]});
            sum += 1ll * cost[i];
        }
        sort(begin(vec), end(vec));
    // finding median
        ll median, i = 0;
        while(i < n and tot < (sum+1)/2) {
            tot += vec[i][1];
            median = vec[i][0];
            i++;
        }
        for(ll i=n-1; i>=0; i--) {
            res += (1ll * abs(nums[i] - median)) * (1ll * cost[i]);
        }
        return res;
    }
};