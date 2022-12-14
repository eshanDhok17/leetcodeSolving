class Solution {
public:
    // same as min time to equal array elements
    int fillCups(vector<int>&a) {
        int sum = 0, mx = 0;
        for(int &i : a) {
            sum += i;
            mx = max(mx, i);
        }
        /*
            observations..
            1. minimum time we require is mx to empty largest cup cup
            2. ifwe can fill every cup such that no water is wasted,
                number of times will be operations would be equal to sum.
                n * 2 = sum
                or n = sum/2;
                if we cant peform perfect operations, we will waste more operations
                hence we take ceil(sum/2);
                
            3. return max(mx, (sum+1)/2);
               because if two cups get empty, we still have 
               one cup left which would take time to get empty.
        */
        return max(mx, (sum+1)/2);
    }
};