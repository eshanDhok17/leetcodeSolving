class Solution:
    def search(self, nums: List[int], target: int) -> int:
        s, e, m = 0, len(nums)-1, 0
        
        while s <= e:
            m = (s + e) // 2
            if nums[m] == target: return m
            elif nums[m] > target: e = m - 1
            else: s = m + 1
        
        return -1 if s > e else m