# LeetCode Problem: 268. Missing Number
# Problem Link: https://leetcode.com/problems/missing-number/


class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        n = len(nums)
        missing = n
        for i in range(n):
            missing ^= i ^ nums[i]
        return missing