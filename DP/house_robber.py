#given List, determine max amount of money you can rob tonight without alerting cops!
#   it will automatically contact the police if two adjacent houses were broken into on the same night.

class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = [0]*(len(nums) + 2)

        for i in range(0, len(nums)):
            dp[i + 2] = max(nums[i] + dp[i], dp[i + 1])
        return dp[len(dp) - 1]
