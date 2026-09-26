# Approach: binary search on columns
# Find the largest element in the middle column. Since it is the column
# maximum, it is already greater than or equal to its vertical neighbours.
# Compare it with its horizontal neighbours to find a peak or choose a side.
class Solution:
    def findPeakGrid(self, mat: list[list[int]]) -> list[int]:
        m = len(mat)
        n = len(mat[0])

        left = 0
        right = n - 1

        while left <= right:
            mid = (left + right) // 2

            # Find maximum element in column mid
            max_row = 0

            for i in range(m):
                if mat[i][mid] > mat[max_row][mid]:
                    max_row = i

            # Check left and right
            left_val = mat[max_row][mid - 1] if mid > 0 else -1
            right_val = mat[max_row][mid + 1] if mid < n - 1 else -1

            curr = mat[max_row][mid]

            if curr > left_val and curr > right_val:
                return [max_row, mid]

            elif left_val > curr:
                # The left neighbour is larger, so move towards it.
                # A peak may also exist on the right, but we only need one.
                # The left side is guaranteed to contain a peak: moving from
                # curr to the larger left_val starts an increasing path.
                # Because curr is the maximum of the middle column, every
                # value in that column is smaller than left_val, so this
                # increasing path cannot cross back into the right half.
                # Since the matrix is finite, that path must eventually reach
                # a value with no larger neighbour, which is a peak.
                # Therefore, the right half can safely be discarded.
                right = mid - 1

            else:
                # The right neighbour is larger than curr, so a peak must
                # exist somewhere in the right half.
                left = mid + 1

        return [-1, -1]


# Time complexity: O(m * log n)
# Space complexity: O(1)
# Here, m is the number of rows and n is the number of columns.