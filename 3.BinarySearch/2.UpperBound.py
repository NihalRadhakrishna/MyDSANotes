# Upper bound returns the first index whose value is greater than target.
# If target is not found, it returns the index where target should be inserted.
# It returns len(arr) when no element is greater than target.


# Own implementation using a half-open range: right = len(arr)
def upper_bound(arr: list[int], target: int) -> int:
    left = 0
    right = len(arr)

    while left < right:
        mid = left + (right - left) // 2

        if arr[mid] <= target:
            left = mid + 1
        else:
            right = mid

    return left


# Time complexity: O(log n)
# Space complexity: O(1)


# Own implementation using an inclusive range: right = len(arr) - 1
def upper_bound_inclusive(arr: list[int], target: int) -> int:
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] <= target:
            left = mid + 1
        else:
            right = mid - 1

    return left


# Time complexity: O(log n)
# Space complexity: O(1)


# Using Python's built-in bisect function
from bisect import bisect_right


def upper_bound_builtin(arr: list[int], target: int) -> int:
    return bisect_right(arr, target)


# Time complexity: O(log n)
# Space complexity: O(1)
