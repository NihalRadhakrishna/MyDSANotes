import math


# Binary search on the answer (lower-bound variation)
# Search the speed range from 1 to max(piles).
# If Koko can finish at a speed, try a smaller speed; otherwise, try a larger one.
class Solution:
    def check(self, piles, k, h) -> bool:
        curr = 0

        for pile in piles:
            curr += math.ceil(pile / k)

        return curr <= h

    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        left = 1
        right = max(piles)

        while left <= right:
            mid = (left + right) // 2

            if self.check(piles, mid, h):
                right = mid - 1
            else:
                left = mid + 1

        return left


# Time complexity: O(n * log(max(piles)))
# Space complexity: O(1)