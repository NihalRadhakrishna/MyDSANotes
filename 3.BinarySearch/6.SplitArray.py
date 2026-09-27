# LeetCode Problem: 410. Split Array Largest Sum
# Problem Link: https://leetcode.com/problems/split-array-largest-sum/


class Solution:
    def check(self, nums, k, curr):
        sm = 0
        subarrays = 1
        for num in nums:
            if sm + num > curr:
                subarrays += 1
                sm = num
            else:
                sm += num
        return subarrays <= k

    def splitArray(self, nums: list[int], k: int) -> int:
        # The answer cannot exceed sum(nums): this is the largest sum when
        # all elements are kept in one subarray.
        right = sum(nums)

        # The answer cannot be smaller than max(nums), because every element
        # must belong to a subarray and cannot be split into smaller parts.
        left = max(nums)

        while left <= right:
            mid = (left + right)//2
            if self.check(nums, k, mid):
                right = mid-1
            else:
                left = mid+1
        return left


# Time complexity: O(n * log(sum(nums) - max(nums) + 1))
# Space complexity: O(1)