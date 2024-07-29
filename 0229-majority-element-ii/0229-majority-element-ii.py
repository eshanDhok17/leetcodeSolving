class Solution:
    def majorityElement(self, v: List[int]) -> List[int]:
        cnt1, cnt2 = 0, 0
        ele1, ele2 = None, None

        for i in range(len(v)):
            if cnt1 == 0 and v[i] != ele2:
                cnt1 = 1
                ele1 = v[i]

            elif cnt2 == 0 and v[i] != ele1:
                cnt2 = 1
                ele2 = v[i]

            elif v[i] == ele1: cnt1 += 1
            elif v[i] == ele2: cnt2 += 1

            else:
                cnt1 -= 1
                cnt2 -= 1

        cnt1 = 0
        cnt2 = 0

        for i in range(len(v)):
            if v[i] == ele1: cnt1 += 1
            if v[i] == ele2: cnt2 += 1

        result = []
        if cnt1 > math.floor(len(v) / 3):
            result.append(ele1)
        if cnt2 > math.floor(len(v) / 3) and ele2 != ele1:
            result.append(ele2)

        return result