class Solution {
public:
    int longestOnes(vector<int>& A, int k) {
        long long ans = 0, sum = 0;
        for(int i=0, j=0; j<size(A); j++) {
            sum += A[j];
            // cout << sum << " " << j << endl;
            if(sum + k >= j-i+1) {
                ans = max((int)ans, j-i+1);
            }
            while(sum + k < j-i+1) {
                sum -= A[i];
                i++;
            }
        }
        return (int)ans;
    }
};