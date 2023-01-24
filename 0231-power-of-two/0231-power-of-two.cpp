class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return ((n & (n-1)) == 0);
        //  3 2 1 0
    // 2 ->     1 0
    // 3 ->     1 1
    }
};