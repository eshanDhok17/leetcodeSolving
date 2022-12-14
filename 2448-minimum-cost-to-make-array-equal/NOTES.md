**Wrong Apporach**
```
typedef long long ll;
class Solution {
public:
ll minCost(vector<int>& nums, vector<int>& cost) {
ll n = size(nums), res = 0;
vector<vector<ll>> vec;
for(ll i=0; i<n; i++) {
vec.push_back({cost[i], nums[i]});
}
sort(rbegin(vec), rend(vec));
ll num = vec[0][1];
for(ll i=n-1; i>=0; i--) {
if(vec[i][1] != num) {
res += ((abs(vec[i][1] - num)) * vec[i][0]);
}
}
return res;
}
};
```