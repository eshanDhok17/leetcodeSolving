class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 1
        j = 1
        while(j < len(nums)):
            if(nums[j-1] == nums[j]):
                j += 1
            else:
                nums[i] = nums[j]
                j += 1
                i += 1
        return i