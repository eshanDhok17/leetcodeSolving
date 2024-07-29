class Solution:
    def fourSum(self, nums: List[int], t: int) -> List[List[int]]:
        res = []
        nums.sort()
        
        for f in range(len(nums)):
            if f > 0 and nums[f] == nums[f - 1]: continue

            for i in range(f + 1, len(nums)):
                if i > f + 1 and nums[i] == nums[i - 1]: continue

                s, e = i + 1, len(nums) - 1
                while s < e:
                    csum = nums[f] + nums[i] + nums[s] + nums[e]
                    if csum == t:
                        res.append([nums[f], nums[i], nums[s], nums[e]])
                        prev, last = nums[s], nums[e]
                        while s < e and nums[s] == prev: s += 1
                        while s < e and nums[e] == last: e -= 1
                        
                    elif csum < t: s += 1
                    else: e -= 1
        return res