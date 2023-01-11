//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long maxPro = -1e9;
	    long long curPro = 1;
	    for(int i=0; i<n; i++) {
	        curPro *= arr[i];
	        maxPro = max(maxPro, curPro);
        // negative may turn out positive later so only refresh when zero
	        if(curPro == 0) curPro = 1;
	    }
	    // need to check from back too since only one element may be negative
	    curPro = 1;
	    for(int i=n-1; i>=0; i--) {
	        curPro *= arr[i];
	        maxPro = max(maxPro, curPro);
	        if(curPro == 0) curPro = 1;
	    }
	    return maxPro;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends