# LeetCode Problem: 2387. Median of a Row Wise Sorted Matrix
# Problem Link: https://leetcode.com/problems/median-of-a-row-wise-sorted-matrix/


from bisect import bisect_right

class Solution:

    def solve(self, matrix, k):
        left = min(row[0] for row in matrix)
        right = max(row[-1] for row in matrix)

        while left <= right:
            mid = (left + right) // 2

            count = 0

            for row in matrix:
                count += bisect_right(row, mid)

            if count < k:
                # Fewer than k elements are <= mid, so the kth smallest
                # element must be greater than mid. Search the right half.
                left = mid + 1
            else:
                # At least k elements are <= mid, so mid may be the answer.
                # Search the left half for the smallest value that still has
                # at least k elements less than or equal to it.
                right = mid - 1

        return left

    def findMedian(self, matrix):
        m = len(matrix)
        n = len(matrix[0])

        total = m * n

        if total % 2 == 1:
            # One middle element
            return self.solve(matrix, total // 2 + 1)

        else:
            # Two middle elements
            a = self.solve(matrix, total // 2)
            b = self.solve(matrix, total // 2 + 1)

            return (a + b) / 2


# Time complexity: O(m * log n * log(value_range))
# Space complexity: O(1)
# Here, m is the number of rows, n is the number of columns, and
# value_range = maximum matrix value - minimum matrix value + 1.