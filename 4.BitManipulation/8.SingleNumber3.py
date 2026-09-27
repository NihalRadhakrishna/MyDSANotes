# LeetCode Problem: 260. Single Number III
# Problem Link: https://leetcode.com/problems/single-number-iii/


class Solution:
    def singleNumber(self, nums: list[int]) -> list[int]:
        xor_all = 0
        for num in nums:
            xor_all ^= num
        
        diff = xor_all & -xor_all # rightmost set bit

        a = 0
        b = 0

        for num in nums:
            if num & diff:
                a ^= num
            else:
                b ^= num
        return [a, b]


# Time complexity: O(n)
# Space complexity: O(1), excluding the returned list