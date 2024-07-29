class Solution:
    def fourSum(self, nums: List[int], t: int) -> List[List[int]]:
        res = []
        # sorting array
        nums.sort()
        
        # finding triplets
        for f in range(0, len(nums)):
            for i in range(f+1, len(nums)):
                s, e = i+1, len(nums)-1
                while s < e:
                    csum = nums[f] + nums[i] + nums[s] + nums[e]
                    prev, last = nums[s], nums[e]

                    if csum == t:
                        res.append([nums[f], nums[i], nums[s], nums[e]])
                        while prev == nums[s] and s < e: s += 1
                        while last == nums[e] and s < e: e -= 1
                    elif csum < t: s += 1
                    else: e -= 1
                        
        res.sort()
        i = 1
        while i < len(res):
            if res[i-1] == res[i]:
                res.remove(res[i])
            else: i += 1
                
        return res