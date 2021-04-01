class Solution:
    def threeSumClosest(self, nums: list(), target: int) -> int:
        nums.sort()
        ans = nums[0] + nums[1] + nums[2]
        for i in range(len(nums) - 2):
            start = i + 1
            end = len(nums) - 1
            while end > start:
                nums_sum = nums[i] + nums[start] + nums[end]
                if abs(nums_sum - target) < abs(ans - target):
                    ans = nums_sum
                if nums_sum == target:
                    return nums_sum
                elif nums_sum < target:
                    start+=1
                else:
                    end-=1
        return ans