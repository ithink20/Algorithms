# All houses at this place are arranged in a circle.
# it will automatically contact the police if two adjacent houses were broken into on the same night.
# determine the maximum amount of money you can rob tonight without alerting the police.

class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #split House RobberII into two House RobberI
        if (len(nums) == 1):
            return nums[0]
        dp1 = [0]*(len(nums) + 1)
        dp2 = [0]*(len(nums) + 2)
        for i in range(0, len(nums) - 1):
            dp1[i + 2] = max(nums[i] + dp1[i], dp1[i + 1])
        ans1 = dp1[len(dp1) - 1]
        for i in range(1, len(nums)):
            dp2[i + 2] = max(nums[i] + dp2[i], dp2[i + 1])
        ans2 = dp2[len(dp2) - 1]
        return max(ans1, ans2)
