class Solution:
    def check(self, nums: List[int]) -> bool:
        cnt=0
        n=len(nums)
        for i in range(n):
            if nums[i]>nums[(i+1)%n]:
                cnt+=1
            if cnt>1:
                return False
        return True
