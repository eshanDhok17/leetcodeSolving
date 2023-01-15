//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> A, int n, int k) {
        // your code here
        deque<int> dq;
        vector<int> res;
        for(int i=0, j=0; j<n; ) {
            while(dq.size() and dq.back() < A[j]) dq.pop_back();
            dq.push_back(A[j]);
            if(j-i+1 < k) j++;
            else {
                res.push_back(dq.front());
                if(A[i] == dq.front()) dq.pop_front();
                i++, j++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends