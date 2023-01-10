//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        int i=0, j=0;
        while(j < n) {
            mp[arr[j]]++;
            if(j-i+1 < k) {
                j++;
            }
            else {
                int uniq = mp.size();
                mp[arr[i]]--;
                if(mp[arr[i]] == 0) mp.erase(arr[i]);
                i++, j++;
                res.push_back(uniq);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends