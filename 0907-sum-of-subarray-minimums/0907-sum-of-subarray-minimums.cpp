class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9+7;
        vector<int> l(n, -1), r(n, n);
        stack<int> st;
         
        // previous smaller element
        for(int i=0; i<n; ++i) {
            while(st.size() and arr[i] < arr[st.top()]) st.pop();
            if(!st.empty()) l[i] = i - st.top();
            else l[i] = i + 1;
            st.push(i);
        }
        while(!st.empty()) {
            st.pop(); // empty stack for another operation
        }
        
        // next smaller element
        for(int i=n-1; i>=0; --i) {
            while(st.size() and arr[i] <= arr[st.top()]) st.pop();
            if(!st.empty()) r[i] = st.top() - i;
            else r[i] = n - i;
            st.push(i);
        }
        int res = 0;
        for(int i=0; i<n; ++i) {
            long long prod = (l[i] * r[i]) % mod;
            prod = (prod * arr[i]) % mod;
            res = (res + prod) % mod; // modding answer
        }
        return res;
    }
};