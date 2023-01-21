class Solution {
public:
    typedef long long ll;
    // in contest thought of sorting but couldnt think anything else
    long long minOperations(vector<int>& n1, vector<int>& n2, int &k) {
        if(k == 0) return n1 == n2? 0 : -1;
        ll moves = 0, debt = 0, n = size(n1);
        /*
            debt concept: 
                we operate on two indices at present moment by taking debt of future
                operation.
                this will make sure we are doing it correct.
                for this testcase:
                    [4,3, 1, 4]
                    [1,3, 7, 1]
            debt was 1 0 -2  1 => 0 which turned out to be zero which is valid answer.
            borrowed -1 0 2 -1
        */
        for(ll i=0; i<n; i++) {
            ll delta = n1[i] - n2[i];
            if(delta % k != 0) return -1;
            debt += delta/k;
            moves += abs(delta/k);
        }
        if(debt == 0) return moves/2; // because we are counting increment and decrement as same
        return -1;
    }
};