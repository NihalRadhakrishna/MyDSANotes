# Lower bound returns the first index whose value is greater than or equal to target.
# If target is not found, it returns the index where target should be inserted.
# It returns len(arr) when every element is smaller than target.


# Own implementation using a half-open range: right = len(arr)
def lower_bound(arr: list[int], target: int) -> int:
    left = 0
    right = len(arr)

    while left < right:
        mid = left + (right - left) // 2

        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid

    return left


# Time complexity: O(log n)
# Space complexity: O(1)


# Own implementation using an inclusive range: right = len(arr) - 1
def lower_bound_inclusive(arr: list[int], target: int) -> int:
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return left


# Time complexity: O(log n)
# Space complexity: O(1)


# Using Python's built-in bisect function
from bisect import bisect_left


def lower_bound_builtin(arr: list[int], target: int) -> int:
    return bisect_left(arr, target)


# Time complexity: O(log n)
# Space complexity: O(1)
