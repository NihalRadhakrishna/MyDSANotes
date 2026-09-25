class Solution:
    def findKthPositive(self, arr: list[int], k: int) -> int:
        left = 0
        right = len(arr) - 1

        while left <= right:
            mid = (left + right) // 2

            missing = arr[mid] - (mid + 1)

            if missing < k:
                left = mid + 1
            else:
                right = mid - 1

        # Number of missing elements before arr[left]
        missing_before = 0 if left == 0 else arr[left - 1] - left

        if left == 0:
            return k

        # The return statement can be simplified to: return left + k
        # missing_before = arr[left - 1] - left
        # answer = arr[left - 1] + (k - missing_before)
        #        = arr[left - 1] + k - (arr[left - 1] - left)
        #        = left + k
        return arr[left - 1] + (k - missing_before)


# Time complexity: O(log n)
# Space complexity: O(1)