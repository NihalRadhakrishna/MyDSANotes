# LeetCode Problem: 774. Minimize Max Distance to Gas Station
# Problem Link: https://leetcode.com/problems/minimize-max-distance-to-gas-station/


# Binary search on the answer, similar to other minimization/maximization problems.
# The difference is that the answer can contain decimal values, so the search
# uses floating-point boundaries and stops when they are within 1e-6 precision.
class Solution:
    def gasStation(self, arr, k):
        def can_make(dist):
            stations = 0

            for i in range(1, len(arr)):
                gap = arr[i] - arr[i - 1]

                # Number of new stations needed in this gap
                stations += int(gap / dist)

                # Avoid counting a station when gap is exactly divisible
                if gap % dist == 0:
                    stations -= 1

                if stations > k:
                    return False

            return True

        left = 0.0
        right = arr[-1] - arr[0]

        while right - left > 1e-6:
            mid = (left + right) / 2

            if can_make(mid):
                right = mid
            else:
                left = mid

        return right


# Time complexity: O(n * log((arr[-1] - arr[0]) / 1e-6))
# Space complexity: O(1)