// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int ans = n;
        int s=0, e=n, m;
        while(s<=e) {
            m=s+(e-s)/2;
            if(isBadVersion(m)) {
                ans=m;
                e=m-1;
            }
            else s=m+1;
        }
        return ans;
    }
};