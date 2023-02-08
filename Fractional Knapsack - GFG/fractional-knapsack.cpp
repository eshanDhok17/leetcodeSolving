//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool cmp(Item i1, Item i2) {
    double unit1 = (i1.value*1.0)/(i1.weight);
    double unit2 = (i2.value*1.0)/(i2.weight);
    return unit1 > unit2;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans = 0;
        sort(arr, arr+n, cmp);
        for(int i=0; i<n; i++) {
            if(arr[i].weight >= W) {
                double unit = (arr[i].value*1.00)/(arr[i].weight);
                ans += (W*unit);
                break;
            }
            ans += arr[i].value;
            W -= arr[i].weight;
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends