//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        /*
            arr[] = {3, 9, 12, 16, 20}
                    totSum = 60/5 = 12
       new array -> {6, 12, 9, 13, 17}
                ->  17 - 6 = 11.
                
            1 2 5 8 10
            3 4 
            26 / 5 => 5.2
           
        wrong intuition---------> 
        sort(arr, arr + n);
        int num = ceil((float)accumulate(arr, arr+n, 0)/n), mx = -1e9, mn = 1e9;
        for(int i=0; i<n; i++) {
            if(arr[i] + k < num) arr[i] += k;
            else if(arr[i] + k >= num) {
                int temp = arr[i] - k;
                if(temp < 0) arr[i] += k;
                else arr[i] -= k;
            }
            mn = min(mn, arr[i]);
            mx = max(mx, arr[i]);
        }
        return mx - mn;
        */
        sort(arr, arr + n);
        int ans = arr[n-1] - arr[0];
        for(int i=1; i<n; i++)
        {
            int mx = max(arr[i-1]+k, arr[n-1]-k), mn = min(arr[0]+k, arr[i]-k);
            if(mn<0) continue;
            ans = min(ans, mx-mn);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends