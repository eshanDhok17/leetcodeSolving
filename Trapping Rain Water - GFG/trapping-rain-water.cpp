//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n) {
        vector<int> l(n), r(n);
        for(int i=1; i<n; i++) {
            l[i] = max(l[i-1], arr[i-1]);
        }
        for(long long i=n-2; i>=0; i--) {
            r[i] = max(r[i+1], arr[i+1]);
        }
        long long res = 0;
        for(long long i=0; i<n; i++) {
            long long waterLevel = min(l[i], r[i]);
            if(waterLevel >= arr[i]) res += waterLevel - arr[i];
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends