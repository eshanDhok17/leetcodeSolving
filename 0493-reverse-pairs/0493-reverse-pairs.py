class Solution:
    def merge(self, nums: List[int], l: int, m: int, r: int, cnt: List[int]) -> None:
        l1, l2 = nums[l:m+1], nums[m+1:r+1]
        i, j = 0, 0
        k = l
        
        while i < len(l1) and j < len(l2):
            if l1[i] > 2 * l2[j]:
                cnt[0] += (len(l1) - i)
                j += 1
            else:
                i += 1
            
        i, j = 0, 0
        k = l
        while i < len(l1) and j < len(l2):
            if l1[i] <= l2[j]:
                nums[k] = l1[i]
                i += 1
                k += 1
            else:
                nums[k] = l2[j]
                j += 1
                k += 1

        while i < len(l1):
            nums[k] = l1[i]
            i += 1
            k += 1

        while j < len(l2):
            nums[k] = l2[j]
            j += 1
            k += 1

    def merge_sort(self, nums: List[int], l: int, r: int, cnt: List[int]) -> None:
        if l >= r:
            return
        m = (l + r) // 2
        self.merge_sort(nums, l, m, cnt)
        self.merge_sort(nums, m + 1, r, cnt)
        self.merge(nums, l, m, r, cnt)
            
    def reversePairs(self, nums: List[int]) -> int:
        cnt = [0]
        self.merge_sort(nums, 0, len(nums) - 1, cnt)
        return cnt[0]