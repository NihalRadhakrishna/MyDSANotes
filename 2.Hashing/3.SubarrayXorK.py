class Solution:
    # Use property: a ^ b = c -> a = b ^ c
    def subarraysXor(self, nums: List[int], k: int) -> int:
        prefix = {0: 1}
        curr = 0
        ans = 0

        for num in nums:
            curr ^= num

            ans += prefix.get(curr ^ k, 0)

            prefix[curr] = prefix.get(curr, 0) + 1

        return ans

