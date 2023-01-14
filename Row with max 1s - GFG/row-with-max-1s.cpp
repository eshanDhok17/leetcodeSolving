//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    /*
	        1. n^2
	        2. n * logn
	    */
	    int ans = 0;
	    int maxOnes = 0;
	    for(int i=0; i<n; i++) {
	        int s=0, e=m-1, mi;
	        while(s<=e) {
	            mi = s+(e-s)/2;
	            if(arr[i][mi]==1)e=mi-1;
	            else s=mi+1;
	        }
	        if(maxOnes < m-s) {
	            maxOnes = m-s;
	            ans = i;
	        }
	    }
	    return maxOnes == 0 ? -1 : ans;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends