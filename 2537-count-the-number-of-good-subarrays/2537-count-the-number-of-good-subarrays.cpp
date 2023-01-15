typedef long long ll;
class Solution {
public:
    long long countGood(vector<int>& nums, int k){
        ll ans =0, cnt = 0;
        int n = nums.size();
        unordered_map<ll, ll>mp;
        for(int j=0, i=0; j<n; j++){
            cnt += mp[nums[j]];
            mp[nums[j]]++;
            while(cnt >= k) {
                ans += n - j;

    /**************************************************************************
        Now, i had confusion like why is answer = 2 when we reach here-->
        nums = [3,1,4,3,2,2,4] for k = 2
                i---------j
        ans is two because we got a good subarray.
        so ans would be 1 at this point right? No.
        because we can also have this subarray which contains our
        previous subarray.
        nums = [3,1,4,3,2,2,4] for k = 2
                i---------j   -> 1
                i-----------j -> 1
        so to calculate ans we find how many elements are
        there on right side of our array, that many subarrays we can have.
        Example:
        index:  0 1 2 3 4 5 6 7 8 9
        nums = [3,1,4,3,2,2,4,7,5,7] for k = 2, n = 10
                i---------j | | | |   -> 1
                i-----------j | | |   -> 1
                i-------------j | |   -> 1
                i---------------j |   -> 1
                i-----------------j   -> 1
        so this subarray can make total of (n-j) = 10-5 => 5 ans
        contributions. we dont include i in equation because it is
        changing to get cnt >= k so i will be always start of good subarray.
        
        
        Loss:
        we remove from first so mp[nums[i]] reduces by 1
        loss is of the numbers who could make pairs with this nums[i]
        hence loss is of those n numbers n numbers are (mp[nums[i]] - 1)
        so we reduce those pair cnts from cnt.
                
    **************************************************************************/
                ll loss = mp[nums[i]] - 1;
                cnt -= loss;
                mp[nums[i]]--;
                i++;
            }
        }
        return ans;
    }
};