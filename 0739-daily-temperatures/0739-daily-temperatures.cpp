class Solution {
public:
    // next greater element to right
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int, int>> st;
        int n = size(temp);
        vector<int> res(n);
        for(int i=n-1; i>=0; i--) {
            if(st.empty()) res[i] = 0;
            while(!st.empty() and st.top().first <= temp[i]){
                st.pop();
            }
            if(!st.empty()) res[i] = st.top().second - i;
            else res[i] = 0;
            st.push({temp[i], i});
        }
        return res;
    }
};