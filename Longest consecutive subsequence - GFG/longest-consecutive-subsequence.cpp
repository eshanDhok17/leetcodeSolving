//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    // 12 mins
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int nums[], int n)
    {
        int ans = 0;
        unordered_set<int> mp;
        for(int i=0; i<n; i++) mp.insert(nums[i]);
        for(int i=0; i<n; i++) {
            if(mp.count(nums[i]-1) == 0) {
                int cntr=1;
                int cur = nums[i];
                while(mp.count(cur+1) != 0) {
                    mp.erase(cur);
                    cur++;
                    cntr++;
                }
                ans = max(ans, cntr);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends