class Solution:
    # Count subarrays with sum equal to k
    def subarraySum(self, nums: list[int], k: int) -> int:
        prefix = {0: 1}
        curr = 0
        ans = 0

        for num in nums:
            curr += num

            ans += prefix.get(curr - k, 0)

            prefix[curr] = prefix.get(curr, 0) + 1

        return ans

    # Time complexity: O(n)
    # Space complexity: O(n)

    # Check whether a subarray with sum equal to k exists
    def hasSubarraySum(self, nums: list[int], k: int) -> bool:
        prefix_sums = {0}
        curr = 0

        for num in nums:
            curr += num

            if curr - k in prefix_sums:
                return True

            prefix_sums.add(curr)

        return False

    # Time complexity: O(n)
    # Space complexity: O(n)