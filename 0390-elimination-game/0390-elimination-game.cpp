class Solution {
public:
    int lastRemaining(int &n) {
        int left = 1, head = 1, step = 1, remaining = n;
        while(remaining > 1) {
            if(left == true or (remaining & 1)) {
                head = head + step;
            }
            step *= 2;
            remaining /= 2;
            left = !left;
        }
        return head;
    }
};