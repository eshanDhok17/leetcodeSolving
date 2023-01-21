class Solution {
public:
    vector<int> twoSum(vector<int>& num, int t) {
        for(int i=0, j=size(num)-1; i<j;) {
            if(num[i]+num[j]==t) {
                return {i+1,j+1};
            }
            (num[i]+num[j]<t)? i++ : j--;
        }
        return {-1, -1};
    }
};