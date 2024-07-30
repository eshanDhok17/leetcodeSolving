class Solution:
    def reverse(self, x: int) -> int:
        
        num = 0
        neg = True if x < 0 else False
        if neg:
            x *= -1
        while x != 0:
            num += x % 10
            num *= 10
            x //= 10
        num //= 10
        
        if -2147483648 > num or num > 2147483647: return 0
        return -1 * num if neg else num