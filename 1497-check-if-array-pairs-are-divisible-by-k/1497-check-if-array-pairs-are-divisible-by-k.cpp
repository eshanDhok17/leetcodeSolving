class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(int &num : arr) {
            int rem = num % k;
            int a = -rem;
            int b = rem > 0 ? k - rem : -(k+rem);
            
            /* map isliye kyuki, map me aisa koi value remainder
               hai kya jo complimentary hai to e to be divisible by k
               for ex-
               mp [3, 1] pada hai when 3 was iterated
               e = 7, k = 5
               rem = 7 % 5 = 2
               we have two options, two compliments,
               either we add or substract. what? -rem or k-rem for rem > 0 or -(k+rem);
               -> is there -k in map? to add to get divisiblity? - No
               -> is there k-rem or -(k+rem) in map? yes, 5-2 = 3. we have one number
               which can compliment
               the current number which is e
               we decrease the unknown compliment number's frequency.
               if it is zero we have two pairs and 0 non pair numbers
               if we still have any frequency left, we have a pair and some unpair numbers
               
           */
            if(mp[a]) {
                mp[a]--;;
            }
            else if(mp[b]) {
                mp[b]--;
            }
            else {
                mp[rem] += 1;
            }
        }
        for(auto &[a, b] : mp) {
            if(b) return false;
        }
        return true;
    }
};