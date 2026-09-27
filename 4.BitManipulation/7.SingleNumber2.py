# LeetCode Problem: 137. Single Number II
# Problem Link: https://leetcode.com/problems/single-number-ii/

class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        ones = 0
        twos = 0

        for num in nums:
            # ones stores bits that have appeared once modulo 3.
            # Remove bits already recorded in twos.
            ones = (ones ^ num) & ~twos

            # twos stores bits that have appeared twice modulo 3.
            # Remove bits now recorded in ones. On the third appearance,
            # a bit is removed from both ones and twos.
            twos = (twos ^ num) & ~ones

        return ones


# Only one iteration is needed. Two identical XOR iterations would cancel
# every number and always produce 0, which does not solve Single Number II.
# Time complexity: O(n)
# Space complexity: O(1)