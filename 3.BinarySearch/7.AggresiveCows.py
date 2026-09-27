# LeetCode Problem: 1552. Magnetic Force Between Two Balls
# Problem Link: https://leetcode.com/problems/magnetic-force-between-two-balls/


class Solution:
    def canPlace(self, arr, k, dist):
        cows = 1
        last = arr[0]

        for i in range(1, len(arr)):
            if arr[i] - last >= dist:
                cows += 1
                last = arr[i]

                if cows == k:
                    return True

        return False

    def aggressiveCows(self, arr, k):
        arr.sort()

        left = 1
        right = arr[-1] - arr[0]

        while left <= right:
            mid = (left + right) // 2

            if self.canPlace(arr, k, mid):
                left = mid + 1
            else:
                right = mid - 1

        # For maximization, valid distances move left to mid + 1.
        # When the loop ends, left is the first invalid distance and
        # right is the largest valid distance, so we return right.
        #
        # For minimization problems, valid answers move right to mid - 1.
        # When that loop ends, right is the last invalid answer and
        # left is the smallest valid answer, so we return left.
        return right


# Time complexity: O(n log n + n * log(arr[-1] - arr[0]))
# Space complexity: O(n) in the worst case for Python's in-place sort;
#                   O(1) auxiliary space excluding the sorting algorithm.