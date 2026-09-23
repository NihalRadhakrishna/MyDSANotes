class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        num_set = set(nums)
        longest = 0
        for num in num_set:
            # Only check for those numbers that are the start of a sequence
            if num-1 not in num_set:
                length = 1

                while num+length in num_set:
                    length += 1
                
                longest = max(longest, length)
        return longest

# Time complexity: O(n)
# Space complexity: O(n)