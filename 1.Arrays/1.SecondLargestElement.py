# Optimized approach
def second_largest(arr):
    largest = float('-inf')
    second = float('-inf')

    for x in arr:
        if x > largest:
            second = largest
            largest = x
        elif x > second and x != largest:
            second = x

    return second

# Time complexity: O(n)
# Space complexity: O(1)


# Heap approach
import heapq


def second_largest_heap(arr):
    unique_elements = set(arr)
    if len(unique_elements) < 2:
        return float('-inf')

    max_heap = [-x for x in unique_elements]
    heapq.heapify(max_heap)
    heapq.heappop(max_heap)
    return -heapq.heappop(max_heap)

# Time complexity: O(n)
# Space complexity: O(n)


# Sorting approach
def second_largest_sorting(arr):
    sorted_arr = sorted(arr, reverse=True)

    for x in sorted_arr[1:]:
        if x != sorted_arr[0]:
            return x

    return float('-inf')

# Time complexity: O(n log n)
# Space complexity: O(n)