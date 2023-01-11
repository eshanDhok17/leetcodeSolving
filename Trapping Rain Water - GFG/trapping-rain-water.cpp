//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n) {
        #define ll long long
        if(n < 3) return 0;
        ll ml = arr[0], mr = arr[n-1];
        ll l = 1, r = n-2;
        ll ans = 0;
        while(l <= r) {
            if(ml < mr) {
                if(ml < arr[l]) {
                    ml = arr[l];
                }
                ans += ml - arr[l];
                l++;
            }
            else {
                if(mr < arr[r]) {
                    mr = arr[r];
                }
                ans += mr - arr[r];
                r--;
            }
        }
        return ans;
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