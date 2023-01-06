class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans=0;
        sort(costs.begin(), costs.end());
        for(int i=0; i<size(costs); i++) {
            if(costs[i] <= coins) {
                coins -= costs[i];
                ans++;
            }
        }
        return ans;
    }
};