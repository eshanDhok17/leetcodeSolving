class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = size(nums);
        if(n < 3) return false; // less than 3 elements
        vector<int> minVals(n, INT_MAX);
        stack<int> st;
        
        for(int i=1; i<n; i++)
            minVals[i] = min(minVals[i-1], nums[i-1]);
        
        for(int i=n-1; i>=0; i--) {
            // remove elements less than or equal to minVals[i] therefore,
            // we have arr[i-1] < x < arr[i+1] and now we only need to find x
            while(!st.empty() and st.top() <= minVals[i]) st.pop();
            
            // This means we found our x such that x > st.top() and x > minVals[i]
            // hence condition found
            if(!st.empty() and st.top() < nums[i]) return true;
            st.push(nums[i]);
        }
        return false;
    }
};