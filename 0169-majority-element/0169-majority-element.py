class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cnt = 1
        ele = nums[0]
        for i in range(1, len(nums)):
            if cnt == 0:
                ele = nums[i]
            if ele == nums[i]:
                cnt += 1
            else: cnt -= 1
        
        cnt = 0
        for i in range(0, len(nums)):
            if ele == nums[i]:
                cnt += 1
        return ele if cnt > len(nums)//2 else -1