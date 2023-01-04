```
class Solution {
public:
// sort and dp
int solve(int i, int prev, vector<int> &tasks, int dp[]) {
if(i < 0) return 0;
if(i - 2 <= 0 and tasks[i-2] == tasks[i]) {
return dp[i] = 1 + solve(i-2, tasks[i-2], tasks, dp);
}
else if(i-1<=0 and tasks[i-1] == tasks[i]) {
return dp[i] = 1 + solve(i-1, tasks[i-1], tasks, dp);
}
return dp[i] = -1;
}
int minimumRounds(vector<int>& tasks) {
sort(begin(tasks), end(tasks));
int n = size(tasks),  dp[n];
return solve(n-1, tasks[0], tasks, dp);
}
};
```
​