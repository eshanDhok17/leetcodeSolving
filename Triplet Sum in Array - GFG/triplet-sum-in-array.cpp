//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int nums[], int n, int X) {
        sort(nums, nums+n);
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int s=i+1, e=n-1, prev, last; s < e; ) {
                int newSum = nums[i] + nums[s] + nums[e];
                if(newSum == X) {
                    cnt++;
                    prev = nums[s], last = nums[e];
                    while(s < e and (newSum > 0 or nums[s] == prev)) s++;
                    while(s < e and (newSum < 0 or nums[e] == last)) e--;
                }
                else if(newSum > X and s < e) e--;
                else s++;
            }
        }
        return cnt;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends