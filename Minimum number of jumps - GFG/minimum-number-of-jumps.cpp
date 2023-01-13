//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        int jumps = 0;
        int maxReachable = -1;
        int curMaxReach = 0; // standing at 0th Index.
        if(arr[0] == 0) return -1;
        for(int i=0; i<n; i++)
        {
            if(i > curMaxReach) return -1;
            if(i == n-1) return jumps;
            maxReachable = max(maxReachable, arr[i] + i);
            if(i == curMaxReach)
            {
                jumps += 1;
                curMaxReach = maxReachable;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends