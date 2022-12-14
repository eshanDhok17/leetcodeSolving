class Solution {
public:
    /*
        self explaination...
        on observing, we have
        1. increased sum = sum + m(n-1)
        since we peform n-1 operations untill we equal all array elements.
        after we get equal elements overall, we have sum of x * n
        2. Increased minimum element with m times to get x.
        
        so,
        1. sum + m(n-1) == x * n
        2. min_element + m = x
        
        solving equations,
        sum + m*n - m = min_element * n + m*n
        sum - m = min_element * n
        therefore, 
        m = sum - min_element * n
        
    */
    int minMoves(vector<int>& nums) {
        long long n = size(nums),
            sum = accumulate(begin(nums), end(nums), 0LL),
            min = *min_element(begin(nums), end(nums));
        return (int)(sum - (min * n));
    }
};