class Solution {
public:
    int maxOperations(vector<int>& nums, int &k) {
        sort(begin(nums), end(nums));
        int n = size(nums), i = 0, j = n-1, cnt = 0;
        while(i < j) {
            if(nums[i] + nums[j] < k) i++;
            else if(nums[i] + nums[j] == k) {
                i++, j--, cnt += 1;
            }
            else j--;
            
        }
        return cnt;
    }
};