class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = size(arr);
        int len = 0;
        for(int i=1; i<n-1; i++) {
            if(arr[i] > arr[i-1] and arr[i] > arr[i+1]) { // peak index found
                int cnt = 1;
                int j=i;
                while(j>0 and arr[j] > arr[j-1]) j--, cnt++; // traverse to left slope of mountain
                j=i;
                while(j<n-1 and arr[j] > arr[j+1]) j++, cnt++; // traverse to right slope of mountain
                len = max(len , cnt);
            }
        }
        return len;
    }
};